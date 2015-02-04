import sys

sum = 0
for line in sys.stdin:
	sum = sum + int(line)

print str(sum)[0:10]
