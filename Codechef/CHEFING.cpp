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
#include <set>

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
		int n; cin >> n;
		vector<string> vec(n);
		set<int> look[26];
		for (int i = 0; i < n; i++) {
			string x; cin >> x;
			for (char c : x) {
				look[c - 'a'].insert(i);
			}
		}
		int cnt = 0;
		for (int i = 0; i < 26; ++i) {
			if ((int)look[i].size() == n) {
				cnt++;
			}
		}

		cout << cnt << '\n';
	}

}
