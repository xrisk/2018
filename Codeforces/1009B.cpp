#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

typedef long long LL;

int main() {

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif
	
	string s; cin >> s;
	
	int last_2 = -1;
	int init_0 = 0;
	int ones = 0;
	int twos = 0;

	map<int, int> m;
	for (int i = 0; i < (int)s.size(); i++) {
		char c = s[i];
		if (c == '0') {
			if (last_2 == -1)
				init_0++;
			else {

				m[last_2] ++;
				// cout << "pushing " << last_2 << ' ' << m[last_2] << '\n';
			}
		} else if (c == '1') {
			ones++;
		} else if (c == '2') {
			twos++;
			last_2++;
		}
	}

	for (int i = 0; i < init_0; i++)
		cout << 0;
	for (int i = 0; i < ones; i++)
		cout << 1;
	for (int i = 0; i < twos; i++) {
		cout << 2;
		for (int j = 0; j < m[i]; j++)
			cout << 0;
	}
	cout << '\n';
}