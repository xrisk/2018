N = 1

def calc(x):
	s = 0
	while x > 0:
		s += x % 10
		x //= 10
	return s

while True:
	if calc(N) == 100 and calc(2 * N) == 110:
		print(N)
		break
