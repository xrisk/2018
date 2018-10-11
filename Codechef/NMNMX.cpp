#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

typedef long long LL;

constexpr int MOD = 1e9 + 7;

// when b is taken under modulo (MOD - 1) (let's call this B)
// then a ^ b (mod MOD) is equal to a ^ B (mod MOD)
// https://math.stackexchange.com/q/2852412/240585

constexpr int MOD2 = MOD - 1;

vector<int> vec(5005);
LL nck[5005][5005];

void precompute() {
	for (int i = 0; i <= 5000; i++) {
		nck[i][0] = 1;
		nck[i][i] = 1;
		for (int j = 1; j <= i - 1; j++) 
			nck[i][j] = (nck[i - 1][j - 1] + nck[i - 1][j]) % MOD2;
	}
}

int get(int n, int k) {
	if (n < 0 || k < 0) return 0;
	if (k > n) return 0;
	return nck[n][k];
}

LL power(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	LL tmp = power(a, b / 2);
	LL sq = (tmp * tmp) % MOD;
	if (b % 2 == 0) return sq;
	else return (a * sq) % MOD;
}

int main() {

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	precompute();

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		for (int i = 0; i < N; i++)
			cin >> vec[i];

		sort(vec.begin(), vec.begin() + N);

		LL counts = get(N - 1, K - 1);
		LL soln = 1;
		for (int i = 0; i < N; i++) {
			int pre = i;
			LL cur_counts = counts;
			if (pre >= K - 1) {
				cur_counts = (cur_counts - get(pre, K - 1) + MOD2) % MOD2;
			} 
			int post = N - i - 1;
			if (post >= K - 1) {
				cur_counts = (cur_counts - get(post, K - 1) + MOD2) % MOD2;
			}
			// cout << vec[i] << " " << cur_counts << '\n';
			soln = (soln * power(vec[i], cur_counts)) %  MOD;
		}
		cout << soln << '\n';
	}
	

}