// Minimum Binary Number
// http://codeforces.com/problemset/problem/976/A

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	int n; cin >> n;
	string s; cin >> s;

	if (s == "0") {
		cout << s << '\n';
		return 0;
	}
	int nzeroes = count(s.begin(), s.end(), '0');
	cout << '1';
	for (int i = 0; i < nzeroes; i++) {
		cout << '0';
	}
	cout << '\n';

}