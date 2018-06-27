#include <iostream>

using namespace std;

typedef long long LL;	

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		LL x = 0;
		while (N--) {
			LL t; cin >> t;
			x ^= (2 * t);
		}
		cout << x << '\n';
	}
}