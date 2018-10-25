// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;


		vector<LL> A(N);
		vector<LL> B(N);

		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		for (int i = 0; i < N; i++) {
			cin >> B[i];
			A[i] %= B[i];
		}

		LL mod = *min_element(B.begin(), B.end());

		LL zeros = 0;
		LL ops = 0;

		for (int i = 0; i < N; i++) {
			if (A[i] >= mod) {
				zeros++;
				ops += (B[i] - A[i]);
				A[i] = 0;
			}
		}

		LL mx = *max_element(A.begin(), A.end());

		// either bring all elements to mx
		// or bring all elemenets to 0
		// or bring all elements to mn != 0

		// cout << mx << '\n';

		LL cost1 = 0;

		for (int i = 0; i < N; i++) {
			// cout << A[i] << ' ';
			cost1 += mx - A[i];
		}
		// cout << '\n';

		LL cost2 = 0;

		for (int i = 0; i < N; i++) {
			if (A[i] != 0) {
				cost2 += B[i] - A[i];
			}
		}

		LL mn = -1;

		for (int i = 0; i < N; i++) {
			if (A[i] != 0) {
				if (mn == -1 || A[i] < mn) {
					mn = A[i];
				}
			}
		}

		LL cost3 = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] > mn) {
				cost3 += (B[i] - A[i] + mn);
			} else if (A[i] < mn) {
				cost3 += (mn - A[i]);
			}
		}





		// cout << "ops " << ops << '\n';
		// cout << "cost1 " << cost1 << '\n';
		// cout << "cost2 " << cost2 << '\n';
		// cout << "cost3 " << cost3 << '\n';

		cout << min(cost1 + ops, min(cost3 + ops, cost2 + ops)) << '\n';


	}
}


