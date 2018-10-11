#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <map>
#include <queue>

typedef long long LL;

using namespace std;

int main() {

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int n, m; cin >> n >> m;

	if (m < n) { cout << "0\n"; return 0; }

	map<int, int> freq;

	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		freq[x]++;
	}

	vector<pair<int, int> > avail;
	for (auto i : freq) {
		avail.push_back(make_pair(i.second, 0));
	}

	// map<int, vector<int> > used;
	for (int i = 0; i < n; i++) {
		// cout << "foo" << i << endl;
		int max = -1; int maxpos = -1;
		for (int j = 0; j < (int)avail.size(); j++) {
			// cout << "foo" << i << endl;
			int x = avail[j].first / (avail[j].second + 1);
			if (x > max) { max = x; maxpos = j;}
		}
		avail[maxpos] = make_pair(avail[maxpos].first, avail[maxpos].second + 1);
		// used[i].push_back()
	}
	int days = INT_MAX;
	for (auto x : avail) {
		// cout << x.first << ' ' << x.second << '\n';
		if (x.second > 0) {
			days = min(days, x.first / x.second);
		}
	}

	cout << days << '\n';
}