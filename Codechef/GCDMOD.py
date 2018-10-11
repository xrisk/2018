from math import log10, gcd, floor

mod = int(1e9 + 7)

T = int(input())
for _ in range(T):
	A, B, N = map(int, input().split())
	sz1 = max(floor(N * log10(A)), floor(N * log10(B))) + 2
	diff = A - B
	if diff == 0:
		print((pow(A, N, mod) + pow(B, N, mod)) % mod)
	elif diff == 1:
		print(1)
	else:
		one = (pow(A, N, diff) + pow(B, N, diff)) % diff
		print(gcd(one, diff) % mod)
