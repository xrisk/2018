#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <iomanip>

using namespace std;

typedef long long LL;

int main() {

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	LL n, m; cin >> n >> m;

	LL t = 0;
	while (m--) {
		LL x, d; cin >> x >> d;

		if (d > 0) {
			if (n != 1) {
				LL sum = n * (n - 1) / 2;
				t += sum * d;
			}
			t += x * n;
			
		} else if (d < 0) {
			if (n != 1) {
				LL k = n / 2;
				// cout << "k=" << k << '\n';
				LL sum = k * (k + 1) / 2 + (n - k) * (n - k - 1) / 2;
				// cout << "sum=" << sum << '\n';
				t += sum * d;
			}
			t += x * n;
		} else {
			t += x * n;
		}
		
	
	}


	cout << setprecision(18) << fixed << (long double) t / (long double) n << '\n';
	

}