// rishav.io

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <climits>
#include <utility>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

char rekt(char c) {
	if      (c == 'R') return 'P';
	else if (c == 'P') return 'S';
	else return 'R';
}

void solve() {
	int A; cin >> A;
	vector<string> vec(A);
	for (int i = 0; i < A; i++) {
		cin >> vec[i];
		while (vec[i].size() < 500) {
			vec[i] += vec[i];
		}
		vec[i].resize(500);
	}

	string out;

	for (int idx = 0; idx < 500; idx++) {
		set<char> q;
		for (string x : vec) {
			if (x[idx] != '_')
				q.insert(x[idx]);
		}
		if (q.size() == 3) {
			cout << "IMPOSSIBLE\n";
			return;
		} else if (q.size() == 1) {
			out += rekt(*q.begin());
			cout << out << "\n";
			return;
		} else {
			auto it = q.begin();
			char fst = *it;
			char snd = *(++it);
			if (snd == rekt(fst)) {
				out += snd;
			} else {
				out += fst;
			}
			char added = out[out.size() - 1];
			for (int i = 0; i < A; i++) {
				if (vec[i][idx] != added) {
					vec[i] = '_';
					vec[i].resize(500, '_');
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int T; cin >> T;
	for (int _t = 1; _t <= T; _t++) {
		cout << "Case #" << _t << ": ";
		solve();
	}
}