#!/usr/bin/env python
import sys, socket
from struct import pack
from binascii import hexlify

HOST = sys.argv[1]
PORT = 2999
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((HOST,PORT))

data = s.recv(1024)
print "%s" % data

value = data.split()[2]
value = value[1:-1]
value = int(value)

print "[*] Big Endian 0x%x" %value
value = pack("<I", value)

print "[*] Little Endian 0x%x" %value
s.sendall(value)

data = s.recv(1024);
print "%s" % data

s.close()
