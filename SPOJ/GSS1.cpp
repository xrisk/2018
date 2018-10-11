// rishav.io


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long LL;
constexpr int NMAX = 50000 + 5;

int N;


struct S {
	LL max_pref = 0, max_suff = 0, max_interval = 0, sum = 0;
};

S combine(S l, S r) {
	S ret = {0};

	ret.max_pref = max(l.max_pref , l.sum + r.max_pref);
	ret.max_suff = max(r.max_suff, r.sum + l.max_suff);
	ret.sum = l.sum + r.sum;
	ret.max_interval = max({l.max_interval, r.max_interval, l.max_suff + r.max_pref});
	
	return ret;
}

vector<S> t(2 * NMAX);

void build() {

	for (int i = N - 1; i > 0; i--) {
		t[i] = combine(t[i<<1], t[i<<1|1]);
	}

}

S query(int l, int r) {
	S resl, resr;
	bool lset = false, rset = false;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		// cout << l << ' ' << r << '\n';
		if (l&1) {
			if (lset) resl = combine(resl, t[l++]);
			else {
				resl = t[l++];
				lset = true;
			}
		}
		if (r&1) {
			if (rset) resr = combine(t[--r], resr);
			else {
				resr = t[--r];
				rset = true;
			}
		}
	}
	if (lset && rset) return combine(resl, resr);
	else if (lset) return resl;
	return resr;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	cin >> N;
	for (int i = 0; i < N; i++) {
		LL x; cin >> x; 
		t[N + i] = {x, x, x, x};
	}

	build();

	int Q; cin >> Q;
	while (Q--) {
		int l, r; cin >> l >> r;
		l--;
		cout << query(l, r).max_interval << '\n';
	}

}
