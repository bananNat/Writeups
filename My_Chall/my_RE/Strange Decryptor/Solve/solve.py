SHORT_SIZE = 8
 

def leftRotate(x, d):
    return ((x << d) & 0xff) | ((x >> (SHORT_SIZE - d)) & 0xff)
 

def rightRotate(x, d):
 
    return (x >> d) | ((x << (SHORT_SIZE - d)) & 0xFF)

byte_decode = [0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a]

byte_encode = [0xed,0xda,0x67,0x3d,0x63,0x4c,0xce,0x65]

key = ""

for i in range(0,8):
    byte = (byte_decode[i] + i) & 0xff
    byte = rightRotate(byte,i)
    byte = byte ^ byte_encode[i]
    key += chr(byte)

print(key)