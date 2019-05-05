// rishav.io

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <climits>
#include <utility>

using namespace std;

typedef long long LL;

int main() {

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int n; cin >> n;

	set<int> a;
	set<int, greater<int>> b;
	
	while (n--) {
		int x; cin >> x;
		if (a.find(x) == a.end()) {
			a.insert(x);
		} else if (b.find(x) == b.end()) {
			b.insert(x);
		} else {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	cout << a.size() << '\n';
	for (auto c : a) {
		cout << c << ' ';
	}
	cout << '\n';
	cout << b.size() << '\n';
	for (auto c : b) {
		cout << c << ' ';
	}
	cout << '\n';
}