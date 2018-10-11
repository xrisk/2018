// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <set>

typedef long long LL;

using namespace std;

LL reduce(LL x) {
	LL s = 0;
	while (x) {
		s += x % 10;
		x /= 10;
	}
	if (s < 10) return s;
	else return reduce(s);
}

LL count_reduce(LL x) {
	if (x < 10) return 0;
	LL s = 0;
	while (x) {
		s += x % 10;
		x /= 10;
	} 
	return 1 + count_reduce(s);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int T; cin >> T;
	while (T--) {
		LL N, D; cin >> N >> D;
		LL rn = reduce(N);
		LL rd = reduce(D);

		// cout << rn << ' ' << rd << '\n';

		set<LL> st;

		int minsofar = rn;
		

		int minctr = 0;
		int ctr = 0;

		while (true) {
			if (st.find(rn) != st.end())
				break;

			st.insert(rn);
			
			rn = reduce(rn + rd);

			ctr++;
			if (rn < minsofar) {
				minsofar = rn;
				minctr = ctr;
			}
		}

		cout << minsofar << ' ' << minctr + count_reduce(N + minctr * D) << '\n';
	}

}