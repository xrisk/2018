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

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		string s; cin >> s;
		string l, r;
		for (char c: s) {
			if (c == '0') {
				l.push_back('0');
				r.push_back('0');
			}
			else if (c != '5') {
				l.push_back(c - 1);
				r.push_back('1');
			} else {
				l.push_back('3');
				r.push_back('2');
			}
		}
		cout << "Case #" << t << ": " << l << " " << r << '\n';
	}


	
}