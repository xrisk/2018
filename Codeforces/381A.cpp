// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

typedef long long LL;

int sc[2];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int n; cin >> n;
	deque<int> dq;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		dq.push_back(x);
	}

	int mv = 0;
	while (!dq.empty()) {
		if (dq.front() >= dq.back()) {
			sc[(mv++)%2] += dq.front();
			dq.pop_front();
		} else {
			sc[(mv++)%2] += dq.back();
			dq.pop_back();
		}
	}
	cout << sc[0] << ' ' << sc[1] << '\n';

}
