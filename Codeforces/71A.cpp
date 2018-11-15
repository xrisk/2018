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
	while (n--) {
		string s; cin >> s;
		if (s.size() <= 10)
			cout << s << '\n';
		else {
			cout << s[0];
			cout << (int)s.size() - 2;
			cout << s.back() << '\n';
		}
	}

}
