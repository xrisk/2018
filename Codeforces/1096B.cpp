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

constexpr int MOD = 998244353;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int n; cin >> n;
	string line;
	cin >> line;
	line += '.';
	vector<pair<char, int>> blocks;

	int last = line[0];
	int cur_len = 1;
	for (int i = 1; i < (int)line.size(); i++) {
		char c = line[i];
		if (c != last) {
			blocks.push_back({last, cur_len});
			last = c;
			cur_len = 1;
		} else {
			cur_len++;
		}
	}

	LL tmp = 0;

	LL cnt = blocks.size();
	for (int i = 0; i < cnt; i++) {
	
		if (i == 0 || i == (cnt - 1)) {
			// try to make this the only block
			tmp = (tmp + blocks[i].second) % MOD;
		} 
		// if ((i + 2) < cnt && blocks[i + 2].first == blocks[i].first) {
		// 	if (i == 0 && (i + 2 + 1) == cnt) {
		// 	// try to merge this block and the next block
		// 	tmp = (tmp + (blocks[i].second * blocks[i + 2].second) % MOD) % MOD;
		// 	}
		// }
		// cout << i << ' ' << tmp << '\n'
	}

	if (blocks[0].first == blocks[cnt - 1].first) {
		tmp = (tmp + (blocks[0].second * blocks[cnt - 1].second) % MOD) % MOD;
	}

	tmp = (tmp + 1) % MOD;

	cout << tmp << '\n';


}
