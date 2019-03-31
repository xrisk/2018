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

	int n; cin >> n;
	vector<int> vec(n - 1);

	for (int i = 0; i < n - 1; ++i)
		cin >> vec[i];
	int r = 0;
	int lowest = 0;
	for (auto x : vec) {
		r += x;
		lowest = min(lowest, r);
	}

	int first = 1 - lowest;
	vector<int> perm;
	perm.push_back(first);
	
	map<int, bool> check;
	check[first] = true;
	for (auto x : vec) {

		first += x;
		// cout << "x=>" << first << endl;
		perm.push_back(first);
		// cout << first << endl;
		check[first] = true;
		
	}
	bool fl = true;
	for (int i = 1; i <= n; ++i) {
		if (!check[i]) {
			fl = false; break;
		}
	}
	if (fl) {
		for (auto x : perm) 
			cout << x << ' ';
	} else {
		cout << "-1";
	}

	cout << '\n';
	
}



