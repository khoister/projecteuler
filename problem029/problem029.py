result = set()
for i in range(2,101):
	val = i
	for j in range(2,101):
		val = val * i
		result.add(val)
print len(result)
