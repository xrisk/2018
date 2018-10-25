from bisect import bisect_right
import sys

from sys import exit

best = -1

def recurse(arr, k, recur=0):
	global best
	# recur = 0
	# pri
	j = bisect_right(arr, k)
	cnt = 0
	for x in arr:
		if x > k:
			cnt += 1
	if cnt <= 1:
		if best == -1 or sum(arr) > best:
			best = sum(arr)
			print(arr, best)

	for it in range(j, len(xs)):
		# arr2 = arr[:]
		# arr
		for it2 in range(it + 1, len(xs)):
			arr2 = arr[:]
			arr2[it] -= 1
			arr2[it2] -= 1
			arr2.sort()
			recurse(arr2, k)


sys.stdin = open("input.txt")

T = int(input())


for _ in range(T):
	n, k = [int(x) for x in input().split()]
	xs = [int(x) for x in input().split()]
	xs.sort()
	recurse(xs, k)
	print(best)