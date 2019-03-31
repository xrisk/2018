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

using namespace std;

typedef long long LL;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int N, Q; cin >> N >> Q;
	vector<int> vec(N);
	vector<int> pref(N + 1);
	int x = 0;
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
		x ^= vec[i];
		if (i == 0) pref[i] = vec[i];
		else pref[i] = pref[i - 1] ^ vec[i];
	}
	pref[N] = x;
	while (Q--) {
		int k; cin >> k;
		k--;
		k %= (N + 1);
		// cout << "pref" << k << '\n';
		if (k == N) cout << "0\n";
		else {
		LL soln = pref[k];
		cout << soln << '\n';
	}
	}

}
