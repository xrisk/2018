#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	int n, k; cin >> n >> k;
	vector<int> vec(n);

	for (int i = 0; i < n ;i++) 
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	if (k == 0) {
		if (vec[0] == 1) {
			cout << "-1\n";
		} else {
			cout << vec[0] - 1 << '\n';
		}
		return 0;
	}
	if (k == n) {
		cout << vec[n - 1] << '\n';
		return 0;
	}

	for (int i = 0; i < (int)vec.size(); i++) {
		int pos = upper_bound(vec.begin(), vec.end(), vec[i]) - vec.begin();
		// cout << pos << '\n';
		if (pos == k) {
			cout << vec[i] << '\n';
			return 0;
		}
	}

	cout << "-1\n";
}
