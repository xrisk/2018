import Queue

T = int(raw_input())

for _ in range(T):

	N, D = [int(x) for x in raw_input().split()]

	best_so_far = -1
	best_so_far_cnt = 0

	q = Queue.PriorityQueue()
	q.put((0, N))

	seen = {}

	def reduce(x):
		s = 0
		while x > 0:
			s += x % 10
			x //= 10
		return s

	for _ in range(int(10000)):
		if q.empty():
			break

		cnt, val = q.get()
		# print(val, cnt)
		
		if val not in seen:
			seen[val] = cnt
			q.put((cnt + 1, reduce(val)))
			q.put((cnt + 1, val + D))


	ret = min(seen.iterkeys())
	print("{} {}".format(ret, seen[ret]))