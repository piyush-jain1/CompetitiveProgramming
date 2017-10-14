f=open("input.txt", "r")
n = int(f.read())
ans = 1
while n!=1 :
	if n >= 10 :
		ans *= 10
	else :
		ans *= 9
	n -= 1
ans *= 8
f= open("output.txt","w")
f.write(''+str(ans)+'\n')
f.close()