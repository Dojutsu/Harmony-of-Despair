"""Characterization of current behavior, not acceptance tests for a fix."""
import contextlib
import io
import socket
import threading
import unittest
from tools.master_server.server import (RendezvousRegistry, RendezvousServer,
    RENDEZVOUS_PACKET, RENDEZVOUS_MAGIC, RENDEZVOUS_VERSION, RENDEZVOUS_REGISTER)

class GameplayBoundaryAudit(unittest.TestCase):
    def test_distinct_sockets_independent_mapping_then_completion_removes_gameplay(self):
        now=[1000.0]
        registry=RendezvousRegistry(clock=lambda:now[0], rendezvous_host="127.0.0.1")
        client=registry.issue("session", "client-a", "invite_code_private_eligible")
        host=registry.pending("session")[0]
        server=RendezvousServer(("127.0.0.1",0),registry)
        worker=threading.Thread(target=server.serve_forever,daemon=True)
        worker.start()
        self.addCleanup(worker.join,2)
        self.addCleanup(server.shutdown)
        def sock():
            s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
            s.bind(("127.0.0.1",0));s.settimeout(.25)
            self.addCleanup(s.close)
            return s
        h,a1,a2=sock(),sock(),sock()
        def register(s,identity,participant,role):
            now[0]+=.1
            packet=RENDEZVOUS_PACKET.pack(RENDEZVOUS_MAGIC,RENDEZVOUS_VERSION,
                RENDEZVOUS_REGISTER,participant,role,bytes.fromhex(identity["attempt_id"]),
                bytes.fromhex(identity["capability"]),b"\0"*4,0,b"\0"*4,0)
            s.sendto(packet,server.address)
            try:return RENDEZVOUS_PACKET.unpack(s.recvfrom(1024)[0])
            except socket.timeout:return None
        discovery=register(a1,client,1,0)
        self.assertIsNotNone(discovery)
        self.assertNotEqual(a1.getsockname()[1],a2.getsockname()[1])
        self.assertIsNotNone(register(h,host,0,1))
        gameplay=register(a2,client,1,1)
        self.assertIsNotNone(gameplay)
        self.assertEqual(discovery[8],a1.getsockname()[1])
        self.assertEqual(gameplay[8],a2.getsockname()[1])
        self.assertNotEqual(discovery[8],gameplay[8])
        self.assertIsNone(registry._attempts[bytes.fromhex(client["attempt_id"])].admission)
        # Registration currently requires neither an armed grant nor membership.
        self.assertTrue(registry.complete("session",client["attempt_id"],host["capability"]))
        self.assertIsNone(register(a2,client,1,1))
        print("AUDIT_PROVEN: distinct discovery/gameplay UDP mappings; gameplay registration accepted before admission; completion prevents later gameplay registration")

    def test_participant_capability_has_no_role_or_socket_binding(self):
        now=[1000.0]
        registry=RendezvousRegistry(clock=lambda:now[0],rendezvous_host="127.0.0.1")
        a=registry.issue("session","a")
        b=registry.issue("session","b")
        aid,acap=bytes.fromhex(a["attempt_id"]),bytes.fromhex(a["capability"])
        bid,bcap=bytes.fromhex(b["attempt_id"]),bytes.fromhex(b["capability"])
        self.assertIsNone(registry.register(bid,acap,1,1,("203.0.113.10",40000)))
        self.assertIsNotNone(registry.register(aid,acap,1,0,("203.0.113.10",40000)))
        self.assertIsNotNone(registry.register(aid,acap,1,1,("203.0.113.10",41000)))
        self.assertIsNotNone(registry.register(bid,bcap,1,1,("203.0.113.10",42000)))
        now[0]+=.1
        self.assertIsNotNone(registry.register(aid,acap,1,1,("203.0.113.10",43000)))
        self.assertEqual(registry._attempts[aid].endpoints[(1,1)],("203.0.113.10",43000))
        self.assertEqual(registry._attempts[bid].endpoints[(1,1)],("203.0.113.10",42000))
        print("AUDIT_PROVEN: participant capabilities are distinct, but one capability spans roles and permits another source endpoint to replace its gameplay mapping")

if __name__=="__main__":unittest.main(verbosity=2)
