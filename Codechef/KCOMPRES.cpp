// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <map>

typedef long long LL;

using namespace std;

constexpr int NMAX = 1e5 + 5;
int N;

map<int, vector<int> > store;

vector<int> t(2 * NMAX);
vector<int> tmp(NMAX + 5);

void modify(int p, int value) {
	for (t[p += N] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p ^ 1]);
}

int query(int l, int r) {
	int res = INT_MIN;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = max(res, t[l++]);
		if (r&1) res = max(res, t[--r]);
	}
	return res;

}

bool check(int K, int S) {

	fill(t.begin(), t.end(), 0);
	for (auto x : store) {

			int sz = x.second.size();
			for (int i = 0; i < sz; i++) {
				int l = max(0, x.second[i] - K);
				int r = min(N, x.second[i] + K + 1);

				tmp[i] = query(l, r) + 1;
				// cout << l <<  ' ' << r  << ' ' << tmp[i] << '\n';
			}

			for (int i = 1; i < sz; i++) {
				if ((x.second[i] - x.second[i - 1]) <= K) {
					tmp[i] = tmp[i - 1] = max(tmp[i], tmp[i - 1]);
				}
			}

			for (int i = sz - 1; i >= 1; i--) {
				if ((x.second[i] - x.second[i - 1]) <= K) {
					tmp[i] = tmp[i - 1] = max(tmp[i], tmp[i - 1]);
				}	
			}

			for (int i = 0; i < sz; i++) {
				
				modify(x.second[i], tmp[i]);
			}
		
	
	}

	LL sum = 0;
	for (int i = N; i < 2 * N; i++)
		sum += t[i];
	return sum <= S;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int T; cin >> T;
	while (T--) {

		store.clear();

		int S; cin >> N >> S;


		for (int i = 0; i < N; i++) {
			int x; cin >> x;
			store[x].push_back(i);
		}

		int lo = 0, hi = N;

		if (check(hi, S)) {
			cout << hi + 1 << '\n';
		} else {
			while (lo < hi) {
				int mid = lo + (hi - lo) / 2;
				if (check(mid, S)) {
					lo = mid + 1;
				} else {
					hi = mid;
				}
			}

			cout << lo << '\n';

		}

		
	}

}