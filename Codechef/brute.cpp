#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

typedef long long LL;

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;

	while (T--) {
		int N; cin >> N;

		vector<LL> vec(N);

		for (int i = 0; i < N; i++) {
			cin >> vec[i];
		}

		LL ans = LLONG_MAX;
		vector<LL> ansvec;

		for (int j = 0; j < 1<<N; j++) {

			int cpy = j; int idx = 0;
			vector<LL> v2(vec);

			while (cpy != 0) {
				if (cpy % 2 == 1) v2[idx] *= -1;
				idx++; cpy /= 2; 
			}

			// for (int ok : v2) {
			// 	cout << ok << " ";
			// }

			bool f = true;
			for (int k = 0; k < N && f; k++) {
				for (int l = k + 1; l < N && f; l++) {

					if (accumulate(v2.begin() + k, v2.begin() + l + 1, 0LL) <= 0) {
						// cout << "false cuz " << k << " " << l + 1 ;
						f = false;
					}
				}	
			}

			if (f) {
				// for (auto ii : v2) {
				// 	cout << ii << " ";
				// } cout << "\n";
				if (accumulate(v2.begin(), v2.end(), 0LL) < ans) {
					ans = accumulate(v2.begin(), v2.end(), 0LL);
					ansvec = vector<LL>(v2);
				}

			}

			// cout << " ; " << f << " , " << accumulate(v2.begin(), v2.end(), 0) << "\n";
		}

		for (LL x : ansvec) cout << x << " ";
		cout << "\n";
	}
