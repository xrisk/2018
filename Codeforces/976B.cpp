#include <iostream>
#include <math.h>

using namespace std;
typedef long long LL;

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	LL n, m, k;
	cin >> n >> m >> k;

	if (k < n) {
		cout << k + 1 << " 1" << '\n';
		return 0;
	}

	k -= (n - 1);

	if (k < m) {
		cout << n << ' ' << k + 1 << '\n';
		return 0;
	}

	k -= (m - 1);

	LL row = (k % (m - 1) == 0) ? (k / (m - 1)) : ((k / (m - 1) + 1));
	k -= ((row - 1) * (m - 1));

	LL col;
	if (row % 2 == 1)
		col = (m) - ((k - 1) % (m - 1));
	else
		col = (2) + ((k - 1) % (m - 1));

	row = n - row;

	cout << row << ' ' << col << '\n';
}