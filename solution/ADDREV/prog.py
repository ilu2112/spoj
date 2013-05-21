a = int(raw_input())
for _ in range(a):
	line = raw_input().split(" ")
	x = int( line[0][::-1].lstrip("0") )
	y = int( line[1][::-1].lstrip("0") )
	print str(x+y)[::-1].lstrip("0")
