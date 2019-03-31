// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;

typedef long long LL;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> atk(N), def(N);
		for (int i = 0; i < N; i++) {
			cin >> atk[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> def[i];
		}
		int ans = -1;
		for (int i = 0; i < N; i++) {
			int pre = (i - 1 + N) % N;
			int aft = (i + 1 + N) % N;
			if (def[i] > (atk[pre] + atk[aft])) {
				ans = max(ans, def[i]);
			}
		}
		cout << ans << '\n';
	}

}
