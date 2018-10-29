// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int n; cin >> n;
	vector<int> vec(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	int mx = *max_element(vec.begin(), vec.end());

	for (int k = mx; ; k++) {

		int aw = 0; int opp = 0;
		for (int x : vec) {
			opp += x;
			aw += k - x;
		}

		if (aw > opp) {
			cout << k << '\n';
			return 0;
		}
	}

}
