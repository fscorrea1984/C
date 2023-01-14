import socket
import struct

IP="192.168.0.25"
PORT=2999


# Create client socket and connect to the IP/PORT
s1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s1.connect(("localhost", PORT))

#x Receive data from the server
data = s1.recv(2048)
print data

number = int( data.split("'")[1] )
number_hex = hex(number)

number_le = struct.pack("I", number_le)[0]
number_hex_le = hex(number_le)

print "Original number %s:, in hex format: %s" % (number, number_hex)
print "Little endian number %s:, in hex format: %s" % (number_le, number_hex_le)

# Send data to the server
s1.send(number_le)

# Receive data from the server
data = s1.recv(2048)
print data

# Close the socket
s1.close()
