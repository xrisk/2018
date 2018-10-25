from collections import defaultdict

adj = defaultdict(list)

N = input()
arr = map(int, raw_input().split())


from fractions import gcd

for i in range(N):
	for j in range(i + 1, N):
		if gcd(arr[i], arr[j]) == 1:
			adj[i].append(j)
			adj[j].append(i)


disc = defaultdict(bool)

def dfs(u):
	st = []
	st.append(u)
	while st:
		t = st.pop()
		if disc[t]:
			continue
		disc[t] = True
		for v in adj[t]:
			if not disc[v]:
				st.append(v)

ccount = 0

for i in range(N):
	if not disc[i]:
		ccount += 1
		dfs(i)

print(ccount)



