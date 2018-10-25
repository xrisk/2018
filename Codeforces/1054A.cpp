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

	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;

	int elev = 0;
	int stair = 0;

	if (z != x) {
		elev += t2 * abs(z - x);
	}
	elev += t3; // open door at x
	elev += t3; // close door at x

	elev += t2 * abs(y - x);
	elev += t3; // open door at y

	// cout << elev << '\n';

	stair = t1 * abs(y - x);

	if (elev <= stair) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

}
