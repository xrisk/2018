MOD = int(1e9 + 7)

def fct(x):
	r = 1
	while x > 1:
		r = (r * x) % MOD
		x -= 1
	return r

Q = input()
for _ in range(Q):
	N, T = [int(x) for x in raw_input().split()]
	ret = 1
	for k in range(N + 1, N + T + 2):
		ret = (ret * k) % MOD
	ret = (ret * pow(T + 1, MOD - 2, MOD)) % MOD
	ret = (ret - fct(T)) % MOD

	print(ret)