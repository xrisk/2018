// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	LL n, x; cin >> n >> x;

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		int oo; cin >> oo;
		if (c == '+') x += oo;
		else if (c == '-') {
			if (x >= oo) { x -= oo; }
			else cnt++;
		}
	}

	cout << x << ' '  << cnt << '\n';

}
