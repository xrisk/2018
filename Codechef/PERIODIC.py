import sys
from collections import deque

from fractions import gcd

# sys.stdin = open("input.txt")

T = input()

for _ in range(T):

	n = input()

	xs = [int(x) for x in raw_input().split()]
	
	i = 0
	j = len(xs) - 1

	if xs.count(-1) == n:
		print("inf")
		continue
	
	while xs[i] == -1:
		i += 1

	while xs[j] == -1:
		j -= 1

	xs = xs[i: j + 1]
	
	
	ones = set([])
	for i, val in enumerate(xs):
		if val != -1:
			ones.add(i - val + 1)

	if len(ones) == 1:
		print("inf")
		continue

	ones = list(ones)
	ones.sort()
	g = -1

	for i in range(1, len(ones)):
		diff = ones[i] - ones[i - 1]
		if g == -1:
			g = diff
		else:
			g = gcd(g, diff)

	if max(xs) > g:
		print("impossible")
		continue

	print(g)







