# s = input()

from itertools import product
from random import choice

def do_test(s):

	actions = []
	tmp = s[::]
	tmp = tmp.rstrip('b')
	build = []
	for i, j in enumerate(tmp):
		if j == 'b' and tmp[i + 1] == 'b':
			build.append(j)
			actions.append(0)
			continue
		if j == 'a' and i != (len(tmp) - 1) and tmp[i + 1] == 'a':
			build.append(j)
			actions.append(0)
			continue
		actions.append(1)
		build.append(j)
		build.reverse()
		# else:
	# 	# build.a
	# print(''.join(build) + 'b' * (len(s) - len(build)))
	# return ''.join(build) + 'b' * (len(s) - len(build))

	# print(actions)
	while len(actions) != len(s):
		actions.append(0)
	print(" ".join(map(str, actions)))


def do_brute(s):
	
	minim = -1
	for p in product([True, False], repeat=len(s)):
		tmp = []
		for i, j in enumerate(p):
			tmp.append(s[i])
			if j:
				tmp.reverse()
		r = ''.join(tmp)
		# print(r, sorted(s))
		# if r == ''.join(sorted(s)):
			# print(p)
		if minim == -1 or r < minim:
			minim = r

	# print(minim)
	return minim

# do_brute("bbbabbb")

# while True:
# 	s = ''.join([choice("ab") for _ in range(15)])
# 	# s = "baaabaaaababbba"
# 	print(do_test(s))
# 	if do_brute(s) != do_test(s):
# 		print("WRONG")
# 		print(s)
# 		break

# s = input()
do_test("aabbabab")
