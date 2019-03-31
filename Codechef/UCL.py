from collections import defaultdict

T = int(input())
for _ in range(T):

	tb = defaultdict(int)
	gd = defaultdict(int)
	for _ in range(12):
		
		s = input().split('vs.')
		l, r = s[0], s[1]
		lname, lscore = l.split()[0], int(l.split()[1])
		rname, rscore = r.split()[1], int(r.split()[0])
		if lscore > rscore:
			tb[lname] += 3
		elif rscore > lscore:
			tb[rname] += 3
		elif rscore == lscore:
			tb[lname] += 1
			tb[rname] += 1
		gd[lname] += lscore - rscore
		gd[rname] += rscore - lscore

	arr = []

	for foo, bar in tb.items():
		arr.append((bar, gd[foo], foo))
	# print(arr)
	arr.sort(reverse=True)
	print(arr[0][2], arr[1][2])
