// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int n; cin >> n;
	vector<int> vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	vector<int> dp(n);
	dp[0] = 1;
	int best_so_far = 1;

	for (int i = 1; i < n; i++) {
		int best = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (((vec[i] < 0) ^ (vec[j] < 0)) && abs(vec[j]) < abs(vec[i])) {
				best = max(best, dp[j] + 1);
			}
		}
		dp[i] = best;
		// cout << i << " -> " << dp[i] << '\n';
		best_so_far = max(best_so_far, dp[i]);
	}

	cout << best_so_far  << '\n';

}
