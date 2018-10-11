#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;

typedef long long LL;

int main() {

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif
	
	int n, m; cin >> n >> m;
	vector<int> games(n);
	queue<int> notes;

	for (int i = 0; i < n; i++)
		cin >> games[i];

	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		notes.push(x);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (notes.size() == 0) break;
		int cur = notes.front();
		if (games[i] <= cur) { cnt++; notes.pop(); }
	}
	cout << cnt << '\n';

}