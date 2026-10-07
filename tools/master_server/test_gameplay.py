from __future__ import annotations
import secrets
import socket
import threading
import unittest

from tools.master_server.gameplay import GameplayError
from tools.master_server.server import (SessionRegistry, RendezvousRegistry,
    RendezvousServer, RENDEZVOUS_PACKET, RENDEZVOUS_MAGIC, RENDEZVOUS_VERSION,
    RENDEZVOUS_REGISTER, AttemptPurpose)
from tools.master_server.test_server import payload


class GameplayTests(unittest.TestCase):
    def setUp(self):
        self.now = 1000.0
        self.rv = RendezvousRegistry(clock=lambda: self.now, rendezvous_host="127.0.0.1")
        self.directory = SessionRegistry(clock=lambda: self.now, on_remove=self.rv.remove_session)
        self.host = self.directory.create(payload())
        self.session = self.host.session_id
        self.xbox = "0123456789abcdef"
        self.host_xuid = "0000000000000001"
        self.members = []

    def admit(self, xuid, prepared=True):
        client = self.rv.issue(self.session, str(xuid), AttemptPurpose.INVITE_CODE_PRIVATE_ELIGIBLE)
        host = next(x for x in self.rv.pending(self.session) if x['attempt_id'] == client['attempt_id'])
        key = bytes.fromhex(client['attempt_id'])
        self.rv.register(key, bytes.fromhex(host['capability']), 0, 0, ("198.51.100.1", 40000))
        self.rv.register(key, bytes.fromhex(client['capability']), 1, 0, ("203.0.113.1", 41000+xuid))
        status, admission = self.rv.arm_admission(self.session, client['attempt_id'], client['capability'])
        self.assertEqual(status, "created")
        if prepared:
            self.rv.host_poll(self.session, [dict(attempt_id=client['attempt_id'],
                admission_generation=admission['admission_generation'], lease_revision=1)])
        member = dict(xuid=f"{xuid:016x}", attempt_id=client['attempt_id'],
            admission_generation=admission['admission_generation'])
        self.members.append(member)
        return member, client, host

    def request(self, action, credential, body, session=None):
        return self.directory.gameplay_request(session or self.session, action, credential, body, self.rv)

    def sync(self, members=None, **changes):
        body = dict(xbox_session=self.xbox, host_xuid=self.host_xuid,
            members=self.members if members is None else members)
        body.update(changes)
        return self.request("sync", self.host.registration_token, body)

    def claim(self, member, client, **changes):
        body = dict(member, xbox_session=self.xbox)
        body.update(changes)
        return self.request("claim", client['capability'], body)

    def test_only_host_commit_attestation_issues_gameplay(self):
        member, client, _ = self.admit(2, prepared=False)
        with self.assertRaises(GameplayError):
            self.sync()
        self.assertIsNone(self.claim(member, client))
        self.assertIsNone(self.request("sync", client['capability'], dict(
            xbox_session=self.xbox, host_xuid=self.host_xuid, members=self.members)))
        self.assertEqual(self.rv.gameplay.groups, {})

    def test_discovery_credentials_cannot_register_a_gameplay_socket(self):
        member, client, host = self.admit(2)
        self.sync()
        for participant, view in enumerate((host, client)):
            self.assertIsNone(self.rv.register(bytes.fromhex(view['attempt_id']),
                bytes.fromhex(view['capability']), participant, 1, ('203.0.113.1', 45000)))
        self.assertIsNotNone(self.claim(member, client))

    def test_malformed_client_fields_are_rejected_without_mutation(self):
        member, client, _ = self.admit(2)
        self.sync()
        for value in ([], {}, None, 2, '0'*16, 'G'*16):
            with self.assertRaises(GameplayError):
                self.claim(member, client, xuid=value)
        self.assertEqual(len(self.rv.gameplay.groups[self.session].members), 2)

    def test_exact_member_session_generation_and_secret(self):
        a, ac, _ = self.admit(2)
        b, bc, _ = self.admit(3)
        host = self.sync()
        av, bv = self.claim(a, ac), self.claim(b, bc)
        self.assertEqual(av['xuid'], a['xuid'])
        self.assertEqual(bv['xuid'], b['xuid'])
        self.assertNotEqual(av['member_nonce'], bv['member_nonce'])
        self.assertNotEqual(av['member_capability'], bv['member_capability'])
        self.assertEqual(len(host['links']), 2)
        self.assertEqual(len(av['links']), 2)  # Includes direct A <-> B, not a relay.
        self.assertIsNone(self.claim(b, ac))
        self.assertIsNone(self.claim(a, bc))
        self.assertIsNone(self.claim(a, ac, xuid="0000000000000004"))
        self.assertIsNone(self.claim(a, ac, xbox_session="ffffffffffffffff"))
        self.assertIsNone(self.claim(a, ac, admission_generation="f"*32))
        self.assertIsNone(self.request("claim", ac['capability'], dict(a, xbox_session=self.xbox), "other"))
        with self.assertRaises(GameplayError):
            self.sync(xbox_session="ffffffffffffffff")
        self.assertEqual(self.claim(a, ac)['member_nonce'], av['member_nonce'])

    def test_pair_traffic_keys_are_private_shared_and_stable_across_renewal(self):
        a, ac, _ = self.admit(2)
        b, bc, _ = self.admit(3)
        host = self.sync()
        av, bv = self.claim(a, ac), self.claim(b, bc)
        def link(view, xuid):
            return next(value for value in view['links'] if value['peer_xuid'] == xuid)
        ha, ah = link(host, a['xuid']), link(av, self.host_xuid)
        hb, bh = link(host, b['xuid']), link(bv, self.host_xuid)
        ab, ba = link(av, b['xuid']), link(bv, a['xuid'])
        for left, right in ((ha, ah), (hb, bh), (ab, ba)):
            self.assertTrue(left['traffic_key'] == right['traffic_key'])
            self.assertTrue(len(bytes.fromhex(left['traffic_key'])) == 32)
            self.assertTrue(int(left['traffic_key'], 16) != 0)
            self.assertEqual(left['datagram_protocol'], 1)
            self.assertNotEqual(left['traffic_key'], left['capability'])
        self.assertEqual(len({ha['traffic_key'], hb['traffic_key'], ab['traffic_key']}), 3)
        self.now += 10
        refreshed = self.sync()
        self.assertTrue(link(refreshed, a['xuid'])['traffic_key'] == ha['traffic_key'])
        self.assertTrue(link(self.claim(a, ac), self.host_xuid)['traffic_key'] == ha['traffic_key'])
        self.assertIsNone(self.claim(a, bc))
        for record in self.rv.gameplay.groups[self.session].links.values():
            self.assertNotIn(record.traffic_key.hex(), repr(record))

    def test_departure_and_new_admission_rotate_only_affected_pair_keys(self):
        a, ac, _ = self.admit(2)
        b, bc, _ = self.admit(3)
        initial = self.sync()
        keys = {value['peer_xuid']: value['traffic_key'] for value in initial['links']}
        self.members.remove(a)
        self.sync()
        self.now += 2  # Real attempt issuance rate limit remains enforced.
        anew, acnew, _ = self.admit(2)
        after = self.sync()
        new_keys = {value['peer_xuid']: value['traffic_key'] for value in after['links']}
        self.assertTrue(new_keys[b['xuid']] == keys[b['xuid']])
        self.assertTrue(new_keys[anew['xuid']] != keys[a['xuid']])
        self.assertIsNone(self.claim(a, ac))
        self.assertIsNotNone(self.claim(anew, acnew))

    def test_completion_and_grant_expiry_do_not_retire_gameplay(self):
        a, ac, ah = self.admit(2)
        initial = self.sync()
        self.assertTrue(self.rv.complete(self.session, ac['attempt_id'], ah['capability']))
        self.now += 21
        current = self.sync()
        self.assertEqual(initial['links'], current['links'])
        self.assertIsNotNone(self.claim(a, ac))
        self.assertNotIn(bytes.fromhex(ac['attempt_id']), self.rv._attempts)

    def test_revocation_cleanup_and_replay_preserve_other_member(self):
        a, ac, _ = self.admit(2)
        b, bc, _ = self.admit(3)
        self.sync()
        av, bv = self.claim(a, ac), self.claim(b, bc)
        self.assertIsNone(self.request("revoke", av['member_capability'],
            dict(b, xbox_session=self.xbox, member_nonce=bv['member_nonce'])))
        self.assertIsNotNone(self.request("revoke", av['member_capability'],
            dict(a, xbox_session=self.xbox, member_nonce=av['member_nonce'])))
        self.sync()  # A delayed, authenticated snapshot must not resurrect A.
        self.assertIsNone(self.claim(a, ac))
        after = self.claim(b, bc)
        self.assertEqual(after['member_nonce'], bv['member_nonce'])
        self.assertEqual(len(after['links']), 1)
        self.sync([])
        self.assertIsNone(self.claim(b, bc))
        self.sync()
        self.assertIsNone(self.claim(b, bc))

    def test_membership_lease_and_host_session_expire(self):
        a, ac, _ = self.admit(2)
        self.sync()
        self.now += 46
        self.assertIsNone(self.claim(a, ac))
        self.assertNotIn(self.session, self.rv.gameplay.groups)
        self.assertEqual(self.rv.gameplay.links, {})

    def test_crashed_member_expires_despite_a_live_host(self):
        a, ac, _ = self.admit(2)
        b, bc, _ = self.admit(3)
        self.sync()
        bv = self.claim(b, bc)
        for _ in range(5):
            self.now += 10
            self.directory.heartbeat(self.session, self.host.registration_token, payload())
            self.sync()
            self.assertIsNotNone(self.request('status', bv['member_capability'],
                dict(b, xbox_session=self.xbox, member_nonce=bv['member_nonce'])))
        self.assertIsNone(self.claim(a, ac))
        self.assertIsNotNone(self.claim(b, bc))
        self.assertEqual(len(self.rv.gameplay.groups[self.session].members), 2)

    def test_gameplay_lease_expiry_cannot_resurrect_old_admission(self):
        a, ac, _ = self.admit(2)
        self.sync()
        self.now += 30
        self.directory.heartbeat(self.session, self.host.registration_token, payload())
        self.now += 16
        self.sync()
        self.assertIsNone(self.claim(a, ac))

    def test_independent_same_ip_mappings_and_single_socket_pin(self):
        a, ac, _ = self.admit(2)
        b, bc, _ = self.admit(3)
        host = self.sync()
        av, bv = self.claim(a, ac), self.claim(b, bc)
        self.assertEqual(len({host['logical_ipv4'],av['logical_ipv4'],bv['logical_ipv4']}),3)
        def reg(link, source, role=1, capability=None):
            self.now += .1
            return self.rv.register(bytes.fromhex(link['attempt_id']),
                bytes.fromhex(capability or link['capability']),link['participant'],role,source)
        al = next(x for x in av['links'] if x['peer_xuid']==self.host_xuid)
        bl = next(x for x in bv['links'] if x['peer_xuid']==self.host_xuid)
        self.assertIsNone(reg(al,("203.0.113.1",42002),0))
        self.assertIsNone(reg(al,("203.0.113.1",42002),capability=ac['capability']))
        self.assertIsNotNone(reg(al,("203.0.113.1",42002)))
        self.assertIsNotNone(reg(bl,("203.0.113.1",42003)))
        self.assertIsNone(reg(al,("203.0.113.1",43002)))
        for h in host['links']:
            result=reg(h,("198.51.100.1",43000))
            self.assertEqual(result[1],("203.0.113.1",42002 if h['peer_xuid']==a['xuid'] else 42003))

    def test_six_players_get_five_isolated_direct_links_each(self):
        clients=[self.admit(i) for i in range(2,7)]
        host=self.sync()
        self.assertEqual(len(host['links']),5)
        self.assertEqual(len(self.rv.gameplay.links),15)
        for member,client,_ in clients:
            result=self.claim(member,client)
            self.assertEqual(len(result['links']),5)
            self.assertNotIn(member['xuid'],{p['peer_xuid'] for p in result['links']})
        with self.assertRaises(GameplayError):self.sync(self.members+[self.members[0]])
        self.assertEqual(len(self.rv.gameplay.links),15)

    def test_real_distinct_udp_sockets_register_after_discovery_completion(self):
        a, ac, ah=self.admit(2)
        host=self.sync()
        self.assertTrue(self.rv.complete(self.session,ac['attempt_id'],ah['capability']))
        av=self.claim(a,ac)
        server=RendezvousServer(("127.0.0.1",0),self.rv)
        worker=threading.Thread(target=server.serve_forever,daemon=True)
        worker.start()
        self.addCleanup(worker.join,2);self.addCleanup(server.shutdown)
        sockets=[]
        for _ in range(3):
            s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
            s.bind(("127.0.0.1",0));s.settimeout(.5)
            sockets.append(s);self.addCleanup(s.close)
        h,a1,a2=sockets
        self.assertNotEqual(a1.getsockname()[1],a2.getsockname()[1])
        def register(s,link):
            self.now+=.1
            packet=RENDEZVOUS_PACKET.pack(RENDEZVOUS_MAGIC,RENDEZVOUS_VERSION,RENDEZVOUS_REGISTER,
                link['participant'],1,bytes.fromhex(link['attempt_id']),bytes.fromhex(link['capability']),
                b'\0'*4,0,b'\0'*4,0)
            s.sendto(packet,server.address)
            return RENDEZVOUS_PACKET.unpack(s.recvfrom(1024)[0])
        register(h,host['links'][0])
        answer=register(a2,av['links'][0])
        self.assertEqual(answer[8],a2.getsockname()[1])
        self.assertEqual(answer[10],h.getsockname()[1])
        answer=register(h,host['links'][0])
        self.assertEqual(answer[10],a2.getsockname()[1])
        # Actual payload round trip between these endpoints. Production NAT
        # punch/ACK and translated title traffic are covered by the native fixture.
        a2.sendto(b'client-title-payload',h.getsockname())
        data,source=h.recvfrom(1024);self.assertEqual(data,b'client-title-payload')
        h.sendto(b'host-title-payload',source)
        self.assertEqual(a2.recvfrom(1024)[0],b'host-title-payload')


if __name__ == '__main__':
    unittest.main()
