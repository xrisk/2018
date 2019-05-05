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
typedef pair<int, int> PII;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	string s; cin >> s;
	int n = s.size();
	int a = 0;
	for (char c : s) 
		if (c == 'a') a++;
	int na = n - a;
	// cout << a << ' ' << na << endl;
	if (na >= a) {
		cout << n - (abs(na - a) + 1) << '\n';
	} else {
		cout << n << '\n';
	}


	
}