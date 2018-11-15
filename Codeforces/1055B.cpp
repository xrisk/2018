// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long LL;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	LL n, m, l;
	cin >> n >> m >> l;

	vector<LL> hair(n);

	for (int i = 0; i < n; ++i) {
		cin >> hair[i];
	}

	LL cur_left = -1;
	LL cur_right = -1;

	set<LL> ledge;
	set<LL> redge;

	for (int i = 0; i < n; ++i) {
		if (hair[i] > l) {
			if (cur_left == -1) 
				cur_left = i;
			cur_right = i;
		} else { 
			if (cur_left != -1) {
				ledge.insert(cur_left);
				redge.insert(cur_right);
				cur_left = -1;
				cur_right = -1;
			}
		}
	}

	if (cur_left != -1) {
		ledge.insert(cur_left);
		redge.insert(cur_right);
	}	

	while (m--) {
		int op; cin >> op;
		if (op == 0) {
			cout << ledge.size() << '\n';
		} else {
			LL p, d; cin >> p >> d;
			p--;
			bool prev = (hair[p] > l);
			hair[p] += d;
			if (hair[p] > l && !prev) {
				bool one = redge.find(p - 1) != redge.end();
				bool two = ledge.find(p + 1) != ledge.end();
				if (one && two) {
					redge.erase(p - 1);
					ledge.erase(p + 1);
				} else if (one) {
					redge.erase(p - 1);
					redge.insert(p);
				} else if (two) {
					ledge.erase(p + 1);
					ledge.insert(p);
				} else {
					ledge.insert(p);
					redge.insert(p);
				}
			} 
		}

	}


}
