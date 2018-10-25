// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

bool intersect(PII a, PII b) {
	if (a.first > b.first) {
		swap(a, b);
	}
	if (a.first == b.first && a.second > b.second)
		swap(a, b);
	if (a.second >= b.first) return true;
	else return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int T; cin >> T;
	while (T--) {
		vector<PII> p;
		string s; cin >> s;
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] != '.') {
				int x = s[i] - '0';
				p.push_back(make_pair(i - x, i + x));
			}
		}

		bool f = true;
		for (int i = 0; i < (int)p.size() && f; i++) {
			for (int j = i + 1; j < (int)p.size() && f; j++) {
				PII a = p[i];
				PII b = p[j];
				if (intersect(a, b)) {
					f = false;
				}
			}

		}

		if (f) cout << "safe\n";
		else	cout << "unsafe\n";

		// cout << "------\n";
	}

}
