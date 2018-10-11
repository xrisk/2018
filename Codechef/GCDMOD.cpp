#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>

typedef long long LL;

using namespace std;

constexpr LL MOD = 1e9 + 7;

LL fastpow(LL a, LL b, LL mod) {
	a %= mod;
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b == 2) return (a * a) % mod;
	LL t = fastpow(a, b / 2, mod);
	t = (t * t) % mod;
	if (b % 2 == 0) return t;
	else return (a * t) % mod;
}

LL pow_no_mod(LL a, LL b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b == 2) return a * a;
	LL t = pow_no_mod(a, b / 2);
	if (b % 2 == 0) return t * t;
	else return a * t * t;
}

LL gcd(LL a, LL b) {
	if (a > b) return gcd(b, a);
	if (a == 0) return b;
	return gcd(b % a, a);
}

int main() {

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) {
		LL A, B, N; cin >> A >> B >> N;

		// let's estimate the size of A^N + B^N
		double size1 = floor(N * (log10(A) + log10(B))) + 2;

	
		LL diff = A - B;
		if (diff == 0) {
			cout <<  (fastpow(A, N, MOD) + fastpow(B, N, MOD)) % MOD << '\n';
		} else if (diff == 1) {
			cout << "1\n";
		} else if (size1 <= 17) {
			LL one = pow_no_mod(A, N) + pow_no_mod(B, N);
			cout << gcd(one, diff) << '\n';
		} else {
			// let's compute A^N + B^N under modulo of A - B
			LL one = (fastpow(A, N, diff) + fastpow(B, N, diff)) % diff;

			cout << gcd(one, diff) % MOD << '\n';
		}
	}
}
