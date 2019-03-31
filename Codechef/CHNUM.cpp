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
		int pos = 0, neg = 0;
		while (N--) {
			int x; cin >> x;
			if (x > 0) pos++;
			else	   neg++;
		}
		if (pos == 0 || neg == 0) {
			cout << max(pos, neg) << ' ' << max(pos, neg) << '\n';
		} else {
			cout << max(pos, neg) << ' ' << min(pos, neg) << '\n';
		}
	}

}
	