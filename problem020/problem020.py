def factorial(n):
	f = 1
	for i in range(1,n+1):
		f *= i
	return f

sum = 0
s = str(factorial(100))
for i in range(0, s.__len__()):
	sum += int(s[i])
print sum
