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

	int n, b, d; cin >> n >> b >> d;
	vector<int> sz;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x <= b) sz.push_back(x);
	}

	int t = 0, cnt = 0;
	for (int c : sz) {
		t += c;
		if (t > d) {
			cnt++;
			t = 0;
		}
	}
	cout << cnt << '\n';

}
