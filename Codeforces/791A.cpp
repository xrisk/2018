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

	int a, b; cin >> a >> b;
	int cnt = 0;
	while (true) {
		if (a > b) break;
		a *= 3;
		b *= 2;
		cnt++;
	}
	cout << cnt << '\n';

}
