// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

int row_cnts[105];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int n; cin >> n;

	int max_row = 0;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x > max_row) max_row = x;
		for (int j = 0; j < x; j++)
			row_cnts[j]++;
	}

	for (int i = 0; i < n; i++) {
		int r = n - i;
		int cnt = 0;
		for (int j = 0; j <= max_row; j++) {
			if (row_cnts[j] >= r) 
				cnt++;
		}
		cout << cnt << ' ';
	}

	cout << '\n';

}
