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

	
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			int t; cin >> t;
			if (t == 1) {
				cout << abs(x - 2) + abs(y - 2) << '\n';
			}
		}
	}

}
