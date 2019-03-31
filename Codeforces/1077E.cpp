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

map<int, int> cnts;

bool p(int start

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int n; cin >> n;
	set<int> vec;

	for (int i = 0; i < n; i++) {
		int x; cin >> x; vec.insert(x);
		// cout << "inserting " << x << '\n';
		cnts[x]++;
	}

	int longest = -1;
	set<int> counts;

	for (auto &p : cnts) {
		cout << p.first << ' ' << p.second << '\n';
		counts.insert(p.second);
	}

	int lo = 1;
	int hi = *max_element(counts.begin(), counts.end()) + 1;

	while (lo < hi) {
		int mid = lo + (hi - mid + 1) / 2;
		if (p())
	}
	cout << best << '\n';

}
