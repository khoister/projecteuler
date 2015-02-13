def fib(n):
	if (n < 3):
		return 1

	f = f1 = f2 = 1
	for i in range(2,n):
		f = f1 + f2
		f1 = f2
		f2 = f
	return f


def run():
	i = 1
	while (str(fib(i)).__len__() < 1000):
		i+=1
	return i


print run()
