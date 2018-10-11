#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>

typedef long long LL;
typedef long double LD;

int ITER = 500;

using namespace std;

vector<int> lift;
vector<int> land;

int n, m;

bool can(LD mid) {
	// just lift off from planet 0
	LD fuel_left = mid;
	LD cur_weight = fuel_left + m;

	LD fuel_burnt = cur_weight / lift[0];

	if (fuel_burnt > fuel_left) return false;
	fuel_left -= fuel_burnt;

	for (int i = 1; i < n; i++) {
		cur_weight = fuel_left + m;
		fuel_burnt = cur_weight / land[i];
		if (fuel_burnt > fuel_left) return false;
		fuel_left -= fuel_burnt;
		cur_weight = fuel_left + m;
		fuel_burnt = cur_weight / lift[i];
		if (fuel_burnt > fuel_left) return false;
		fuel_left -= fuel_burnt;
	}

	cur_weight = fuel_left + m;
	fuel_burnt = cur_weight / land[0];
	// cout << "fuel left " << fixed << setprecision(18) << fuel_left << '\n';
	// cout << "fuel_burnt" << fixed << setprecision(18) << fuel_burnt << '\n';
	


	// cout << fixed << setprecision(18) << fuel_left << '\n';
	if (fuel_left > fuel_burnt)
	return true;
	else return false;
}

int main() {

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	cin >> n >> m;
	lift.resize(n);
	land.resize(n);

	LD lo = 0;
	LD hi = 1e9 + 1;

	for (int i = 0; i < n; i++) {
		cin >> lift[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> land[i];
	}

	// if (!can(hi)) {
	// 	cout << "-1\n";
	// 	return 0;
	// }

	LD mid = (lo + hi) / 2;
	while (ITER--) {
		mid = (lo + hi) / 2;
		// cout << lo  << ' ' << hi << '\n';
		if (can(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}

	if (mid == 1e9 + 1) { cout << "-1\n"; return 0;}

	cout << fixed << setprecision(18) << mid << '\n';

}