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
	int cnt = 0;

	while (n--) {
		int a, b, c; cin >> a >> b >> c;
		int r = (a == 1) + (b == 1) + (c == 1);
		if (r >= 2) cnt++;
	}

	cout << cnt << '\n';

}
