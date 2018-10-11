// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <map>

typedef long long LL;

constexpr LL MOD = 1e9 + 7;

using namespace std;

map<pair<LL, LL> , LL > m;

LL dp(LL N, LL K) {
	// cout << N << ' ' << K << '\n';
	if (N <= 0) return 0;
	if (K > N) return 0;
	if (K == 1) return (2 * N);
	if (N == 1) {
		if (K == 0) return 1;
		if (K == 1) return 2;
		return 0;
	}

	if (m.find(make_pair(N, K)) != m.end()) {
		return m[make_pair(N, K)];
	}
	m[make_pair(N, K)] = (dp(N - 2, K - 1) + dp(N - 1, K) + dp(N - 1, K - 1)) % MOD;
	return m[make_pair(N, K)];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int T; cin >> T;
	
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j <= i; j++)
			cout << dp(i, j) << ' ';
		cout << '\n';
	}

}