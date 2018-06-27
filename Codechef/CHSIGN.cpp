#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

constexpr int NMAX = 1e5 + 1;

typedef long long LL;

vector<LL> vec(NMAX);
vector<LL> pos(NMAX);
vector<LL> neg(NMAX);
vector<LL> pos_sub(NMAX);
vector<LL> neg_sub(NMAX);
vector<bool> flip(NMAX);

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;

	while (T--) {
		int N; cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> vec[i];
		}
		

		pos[0] = vec[0];
		neg[0] = -vec[0];

		pos_sub[0] = vec[0];
		neg_sub[0] = -vec[0];

		// for (int i = 1; i < N; i++) {
		// 	pos[i] = vec[i] + pos[i - 1];
		// 	if ((vec[i] - vec[i - 1] > 0) && neg[i - 1] != INT_MAX)
		// 		pos[i] = min(pos[i], vec[i] + neg[i - 1]);
		// 	// ------ 
		// 	if (vec[i - 1] + vec[i] < 0) neg[i] = INT_MAX;
		// 	else neg[i] = -vec[i] + pos[i - 1];


		// }

		for (int i = 1; i < N; i++) {
			// we can put a plus here always

			pos[i] = vec[i] + pos[i - 1];
			pos_sub[i] = min(vec[i], pos_sub[i - 1] + vec[i]);

			// lets try putting a neg before this plus
			if ((vec[i] + neg_sub[i - 1]) > 0 && neg_sub[i  - 1] != LLONG_MAX) {
				pos[i] = min(pos[i], vec[i] + neg[i - 1]);
				pos_sub[i] = min(pos_sub[i], neg_sub[i - 1] + vec[i]);
			}

			// lets try putting a neg here
			// we can only do this if...
			if (pos_sub[i - 1] > vec[i]) {
				neg[i] = pos[i - 1] - vec[i];
				neg_sub[i] = min(-vec[i], pos_sub[i - 1] - vec[i]);
			} else {
				neg_sub[i] = LLONG_MAX;
				neg[i] = LLONG_MAX;
			}
		}

	
		if (pos[N - 1] > neg[N - 1]) flip[N - 1] = true;
		else flip[N - 1] = false;
		for (int i = N - 1; i >= 1; i--) {
			LL cur = flip[i] ? -vec[i] : vec[i];
			LL cur2 = min(pos[i], neg[i]);
			if (neg[i - 1] + cur == cur2) flip[i - 1] = true;
			else flip[i - 1] = false;
		}

		for (int i = 0; i < N; i++) {
			cout << i << " " << pos[i] << " " << neg[i] << " ";
			cout << pos_sub[i] << " " << neg_sub[i] << "\n";
 		}
		

		// cout << min(pos[N - 1], neg[N - 1]) << "\n";

		for (int i = 0; i < N; i++) {
			if (flip[i]) cout << -vec[i] << " ";
			else cout << vec[i] << " ";
		}
		cout << "\n";
	}
}
