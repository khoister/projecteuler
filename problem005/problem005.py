#!/usr/bin python

def is_multiple( n ):
	b = True
	for i in range(2,21):
		if (n%i != 0):
			b = False;
			break

	return b;


n = 20
while ( not is_multiple(n) ):
	n += 1;
else:
	print n
	
