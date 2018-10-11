#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

typedef long long LL;

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif


	int n, m; cin >> n >> m;
	int rem = m;

	if (m < n - 1) {
		cout << "Impossible" << '\n';
		return 0;
	}

	vector<pair<int, int> > vec;

	for (int i = 2; i <= n && rem > 0; i++) {
		vec.push_back(make_pair(1, i));
		rem--;
	}

	for (int i = 2; i <= n && rem > 0; i++) {
		for (int j = i + 1; j <= n && rem > 0; j++) {
			if (__gcd(i, j) != 1) continue;
			vec.push_back(make_pair(i, j));
			rem--;
		}
	}

	if (rem == 0) {
		cout << "Possible\n";
		for (pair<int, int> p : vec) {
			cout << p.first << " " << p.second << "\n";
		}
	} else {
		cout << "Impossible\n";
	}

}