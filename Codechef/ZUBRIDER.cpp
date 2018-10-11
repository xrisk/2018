// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>

typedef long long LL;

using namespace std;

constexpr LL MOD = 1e9 + 7;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		LL kp, ks;; cin >> kp >> ks;
		LL kperf = kp * ks;

		LL N; cin >> N;
		vector<LL> minReq(N);
		vector<LL> speeds(N);
		for (int i = 0; i < N; i++) {
			LL x; cin >> x;
			minReq[i] = floor(kperf / x) + 1;
		}
		for (int i = 0; i < N; i++)
			cin >> speeds[i];

		

		sort(minReq.begin(), minReq.end(), greater<LL>());
		sort(speeds.begin(), speeds.end());

		cout << "minReq => ";
		for (int i = 0; i < N; i++) {
			cout << minReq[i] << " ";
		}
		cout << "\nspeeds => ";
		for (int i = 0; i < N; i++) {
				cout << speeds[i] << " ";
		}
		cout << "\n";

		LL ans = 1;

		int ctr = 0;
		for (LL x : minReq) {
			LL pos = lower_bound(speeds.begin(), speeds.end(), x) - speeds.begin();
			if (pos != 0 && speeds[pos - 1] == x)
				pos--;
			pos = N - pos;
			LL val = max(0LL, pos - ctr++);
			ans = (ans * val) % MOD;
			cout << x << "->" << val << "\n";
		}
		cout << "Case " << t << ": " << ans << "\n";
	}

}