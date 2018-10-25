// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

typedef long long LL;

map<LL, LL> factor(LL x) {
	map<LL, LL> ret;
	for (LL i = 2; i <= (LL)sqrt(x); i++) {
		while (x % i == 0) {
			ret[i]++;
			x /= i;
		}
	}
	if (x > 1) 
		ret[x]++;
	return ret;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	LL n; cin >> n;
	map<LL, LL> r = factor(n);

	LL cnt = 1;

	for (auto p : r) {
		// cout << p.first << ' ' << p.second << '\n';
		cnt *= (p.second + 1);
	}

	cout << cnt << '\n';

}
