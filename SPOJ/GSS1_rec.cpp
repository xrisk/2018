// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

typedef long long LL;

using namespace std;

constexpr int NMAX = 1e5 + 5;

int n, t[4 * NMAX];
int a[NMAX];

void build(int v, int tl, int tr) {
	if (tl == tr) t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

void query(int v, int tl, int tr, int l, int r) {
	if (l > r) return 0;
	if (l == tl && r == tr) return t[v];
	int tm = (l + r) / 2;
	return query(v * 2, tl, tm, l, r) + query(v * 2 + 1, tm + 1, tr, l, r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr) {
		t[v] = new_val;
	} else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos, new_val);
		else 
			update(v * 2 + 1, tm + 1, tr, pos, new_val);
		t[v] = t[2 * v] + t[2 * v + 1];
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

}