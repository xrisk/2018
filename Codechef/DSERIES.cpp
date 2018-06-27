#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

typedef long long LL;

const int MOD = 1e9 + 7;

using namespace std;

// https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/

LL power(LL x, LL y, LL m)
{
    if (y == 0)
        return 1;
    LL p = power(x, y/2, m) % m;
    p = (p * p) % m;
 
    return (y%2 == 0)? p : (x * p) % m;
}
 
LL fct(LL x) {
	LL r = 1;
	while (x > 1) {
		r = (r * x) % MOD;
		x--;
	}
	return r;
}

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int Q; cin >> Q;
	while (Q--) {
		LL N, T; cin >> N >> T;

		LL t2 = 1;
		for (LL i = N + 1; i <= (N + T + 1); i++) {
			t2 = (t2 * (i % MOD)) % MOD;
		}
		// cout << t2 << "\n";
		// t2 = (t2 * modInverse(T + 1, MOD)) % MOD;
		t2 = (t2 * power(T + 1, MOD - 2, MOD)) % MOD;
		if (t2 < 0) t2 += MOD;
		t2 = (t2 - fct(T) + MOD) % MOD;

		cout << t2 << "\n";

	}
}