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

bool perf(LL x) {
	LL f = sqrt(x);
	if (f * f == x) return true;
	else			return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	while (true) {
		LL x; cin >> x;
		if (x == 0) break;
		if (perf(x)) cout << "yes\n";
		else		 cout << "no\n";

	}

}
