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
#include <numeric>

using namespace std;

typedef long long LL;

bool can(int K, LL S, vector<LL> &pref) {
	if ((K - 1) >= (int)pref.size()) return false;
	LL sum = pref[K - 1] + K * (K) * (K + 1) / 2;
	cout << pref[K - 1] << '\n';
	cout << K << " => " << sum << '\n';
	return sum <= S;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int n, S; cin >> n >> S;
	vector<LL> prices(n);

	for (int i = 0; i < n; ++i) {
		cin >> prices[i];
	}

	sort(prices.begin(), prices.end());

	vector<LL> pref(n);


	for (int i = 0; i < (int)prices.size(); ++i) {
		if (i == 0) pref[i] = prices[i];
		else pref[i] = pref[i - 1] + prices[i];
	}

	
	for (int x : pref) {
		cout << x << '\n';
	}

	cout << "-------\n";

	vector<int> arr(n);
	iota(arr.begin(), arr.end(), 0);

	auto it = lower_bound(arr.begin(), arr.end(), 0, 
		[&pref, &S] (int l, int r) -> bool {
			cout << can(l, S, pref);
			return can(l, S, pref);			
	});

	cout << *it << '\n';

	LL val = *it;
	if (val == 0) {
		cout << "0 0\n";
	} else {
		cout << val << ' ' << pref[val] + (val * (val) * (val + 1)) / 2 << '\n';
	}

}
