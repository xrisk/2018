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
	int off = 0;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x < 0) {
			if (off == 0)
				cnt++;
			else
				off--;
		} else {
			off += x;
		}
	}

	cout << cnt << '\n';

}
