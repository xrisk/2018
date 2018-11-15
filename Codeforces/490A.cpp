// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int n; cin >> n;
	vector<int> v[3];

	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		v[x - 1].push_back(i);
	}

	int r =  min(v[0].size(), min(v[1].size(), v[2].size()));
	cout << r << '\n';
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < 3; j++) {
			cout << v[j].back() << ' ';
			v[j].pop_back();
		}
		cout << '\n';
	}

}
