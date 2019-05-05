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
#include <set>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int T; cin >> T;
	while (T--) {

	
		int N, M, K; cin >> N >> M >> K;

		set<PII> plants;

		for (int i = 0; i < K; i++) {
			int x, y; cin >> x >> y;
			plants.insert({x, y});
			// cout << x << ' ' << y << endl;
		}

		
		LL ret = 0;
		for (auto p : plants) {
			int x = p.first, y = p.second;
			LL tmp = 0;
			if (plants.find({x + 1, y}) == plants.end()) tmp++;
			if (plants.find({x, y + 1}) == plants.end()) tmp++;
			if (plants.find({x - 1, y}) == plants.end()) tmp++;
			if (plants.find({x, y - 1}) == plants.end()) tmp++;
			ret += tmp;
		}
		cout << ret << '\n';
	}
}
