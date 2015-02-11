def factorial(n):
	t = 1
	for i in range(1,n+1):
		t *= i
	return t

t = 0
s = str(factorial(100))
for i in range(0, s.__len__()):
	t += int(s[i])
print t
