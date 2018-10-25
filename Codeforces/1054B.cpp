// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int n; cin >> n;
	vector<int> vec(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	if (vec[0] != 0) {
		cout << "1\n";
		return 0;
	}

	int largest = 0;

	for (int i = 1; i < n; i++) {
		if (vec[i] > (largest + 1)) {
			cout << i + 1 << '\n';
			return 0;
		}
		if (vec[i] > largest) largest = vec[i];
	}

	cout << "-1\n";

}
