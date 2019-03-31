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

array<string, 7> days = {"saturday", "sunday", "monday",
			  "tuesday", "wednesday", "thursday",
			  "friday",
			  };

bool in(int x, int L, int R) {
	return L <= x && x <= R;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int T; cin >> T;
	while (T--) {
		string a, b; int L, R;
		cin >> a >> b >> L >> R;

		int ai = find(days.begin(), days.end(), a)    - days.begin();
		int bi = find(days.begin(), days.end(), b)     - days.begin();

		if (ai > bi) bi += 7;
		int diff = bi - ai + 1;

		vector<int> sols;

		// cout << "initial" << diff << '\n';

		while (diff < 105) {
			if (in(diff, L, R)) sols.push_back(diff);
			diff += 7;
		}

		if (sols.size() == 0) {
			cout << "impossible\n";
		} else if (sols.size() == 1) {
			cout << sols[0] << '\n';
		} else {
			cout << "many\n";
		}


	}

}
