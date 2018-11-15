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

bool vis[26];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int cnt = 0;

	while (!cin.eof()) {
		char s; cin >> s;
		if ('a' <= s && s <= 'z') {
			if (!vis[s - 'a']) cnt++;
			vis[s - 'a'] = true;
		}
	}

	cout << cnt << '\n';

}
