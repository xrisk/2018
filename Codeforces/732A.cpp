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

	int k, r; cin >> k >> r;
	int mul = 1;

	while (true) {
		int cur = k * mul;
		if (cur % 10 == r || cur % 10 == 0) {
			cout << mul << '\n';
			return 0;
		}
		mul++;
	}

}
