#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	int n; cin >> n;
	vector<int> vec(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	vector<int> dp(n);
	map<int, int> max_el;

	for (int i = 0; i < n; i++) {
		int x = vec[i];
		if (x == 1) dp[i] = 1;
		else dp[i] = max(1, 1 + max_el[x - 1]);
		max_el[x] = max(max_el[x], dp[i]);
	}
	

	int pos  = max_element(dp.begin(), dp.end()) - dp.begin();

	cout  << dp[pos] << '\n'; int cur = vec[pos];
	vector<int> ans;
	for (int i = pos; i >= 0; i--) {
		if (vec[i] == cur) { ans.push_back(i + 1); cur--; }
	}
	reverse(ans.begin(), ans.end());

	for (int i : ans) 
		cout << i << ' ';
}
