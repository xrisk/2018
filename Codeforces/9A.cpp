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

	int y, w; cin >> y >> w;
	int t = max(y, w);

	int num = 6 - t + 1;
	int denom = 6;
	int g = __gcd(num, denom);
	cout << num / g << '/' << denom / g << '\n';

}
