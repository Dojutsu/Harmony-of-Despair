#!/usr/bin/env python3
"""Validate offline or protected private LAN configuration and launch natively.

Pass normal asset, renderer and controller arguments after --. No invitation
secret is accepted as an argument or printed. Validation does not claim that
actual title gameplay or SteamOS hardware has been tested.
"""
from __future__ import annotations
import argparse
import ipaddress
import os
from pathlib import Path
from private_lan_invitation import inspect_invitation, canonical_path, xuid


def private_ipv4(value: str) -> str:
    try:
        address = ipaddress.IPv4Address(value)
    except ipaddress.AddressValueError as error:
        raise ValueError('Use an explicit loopback or RFC1918 IPv4 literal') from error
    allowed = ('127.0.0.0/8', '10.0.0.0/8', '172.16.0.0/12', '192.168.0.0/16')
    if not any(address in ipaddress.IPv4Network(network) for network in allowed):
        raise ValueError('Direct private LAN requires loopback or RFC1918 IPv4')
    return str(address)


def build_command(game: Path, mode: str, invitation: str | None, local_xuid: int | None,
                  bind_ip: str | None, host_ip: str | None, name: str, discovery_port: int,
                  gameplay_port: int, extra: list[str]) -> list[str]:
    executable = game.resolve(strict=True)
    if not executable.is_file() or not os.access(executable, os.X_OK):
        raise ValueError('Game must be an executable regular file')
    if any(argument.startswith(('--private_lan_', '--session_directory_', '--nat_probe_',
                                '--lan_', '--direct_connect_address', '--user_xuid', '--user_name'))
           for argument in extra):
        raise ValueError('Additional arguments cannot override protected network/profile settings')
    if not 1 <= discovery_port <= 65535 or not 1 <= gameplay_port <= 65535 or discovery_port == gameplay_port:
        raise ValueError('Discovery and gameplay need distinct valid UDP ports')
    if not name or len(name.encode('utf-8')) > 15 or any(ord(character) < 32 for character in name):
        raise ValueError('Display name must be 1–15 UTF-8 bytes without control characters')
    command = [str(executable), *extra, '--private_lan_allow_legacy_diagnostics=false',
               '--session_directory_url=', '--session_directory_invite_code=',
               '--nat_probe_server=', '--nat_probe_attempt=', '--nat_probe_credential=',
               f'--user_name={name}']
    if mode == 'offline':
        if invitation or bind_ip or host_ip:
            raise ValueError('Offline launch does not consume an invitation or network endpoint')
        command.extend(['--lan_online=false', '--private_lan_invitation_file=',
                        '--direct_connect_address=', '--lan_bind_address='])
        if local_xuid is not None:
            if not 0 < local_xuid < 2**64:
                raise ValueError('Invalid local XUID')
            command.append(f'--user_xuid={local_xuid}')
        return command
    if mode not in ('host', 'client') or not invitation or not local_xuid or not bind_ip:
        raise ValueError('Protected launch requires mode, invitation, local XUID and bind address')
    metadata = inspect_invitation(invitation, local_xuid)
    if metadata['role'] != mode:
        raise ValueError('Invitation role does not match selected host/client mode')
    bind_ip = private_ipv4(bind_ip)
    if mode == 'client':
        if not host_ip:
            raise ValueError('Client requires the explicitly trusted host IPv4')
        host_ip = private_ipv4(host_ip)
    elif host_ip and private_ipv4(host_ip) != bind_ip:
        raise ValueError('Host address must match its explicitly selected bind address')
    command.extend([f'--user_xuid={local_xuid}', '--lan_online=true',
                    f'--private_lan_invitation_file={canonical_path(invitation)}',
                    f'--lan_bind_address={bind_ip}', f'--direct_connect_address={host_ip or ""}',
                    f'--lan_discovery_port={discovery_port}', f'--lan_gameplay_port={gameplay_port}'])
    return command


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--game', type=Path, required=True)
    parser.add_argument('--mode', choices=('offline', 'host', 'client'), default='offline')
    parser.add_argument('--invitation')
    parser.add_argument('--xuid', type=xuid, help='Expected profile XUID in hexadecimal')
    parser.add_argument('--bind-ip')
    parser.add_argument('--host-ip')
    parser.add_argument('--name', default='User')
    parser.add_argument('--discovery-port', type=int, default=30741)
    parser.add_argument('--gameplay-port', type=int, default=30742)
    parser.add_argument('--check', action='store_true', help='Validate without starting the executable')
    parser.add_argument('game_arguments', nargs=argparse.REMAINDER)
    arguments = parser.parse_args()
    extra = arguments.game_arguments
    if extra[:1] == ['--']:
        extra = extra[1:]
    try:
        command = build_command(arguments.game, arguments.mode, arguments.invitation, arguments.xuid,
                                arguments.bind_ip, arguments.host_ip, arguments.name,
                                arguments.discovery_port, arguments.gameplay_port, extra)
    except (ValueError, OSError) as error:
        parser.error(str(error))
    if arguments.check:
        print('Launch configuration validated; title/hardware execution was not performed.')
        return 0
    environment = os.environ.copy()
    for variable in list(environment):
        if variable.startswith(('REX_PRIVATE_LAN_', 'REX_SESSION_DIRECTORY_', 'REX_NAT_PROBE_',
                                'REX_LAN_', 'REX_DIRECT_CONNECT_ADDRESS', 'REX_USER_XUID', 'REX_USER_NAME')):
            del environment[variable]
    os.execve(command[0], command, environment)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
