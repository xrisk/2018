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

	int n; cin >> n;
	vector<int> vec(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> vec[i];
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		if (x != 1) vec[x - 1] += (y - 1);
		if (x != n) vec[x + 1] += (vec[x] - y);
		vec[x] = 0;
;	}
	for (int i = 1; i <= n; i++) {
		cout << vec[i] << '\n';
	}

}
