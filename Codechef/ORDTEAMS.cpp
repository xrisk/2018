#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




bool cmp(vector<int> &v1, vector<int> &v2) {
	for (int i = 0; i < 3; i++) {
		if (v1[i] > v2[i]) return false;
	}
	for (int i = 0; i < 3; i++) {
		if (v2[i] > v1[i]) return true;
	}
	return false;
}

void solve() {
	
	vector<int> v[3];
	for (int i = 0; i < 3; i++) {
		v[i].resize(3);
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}

	vector<int> cur_perm = {0, 1, 2};
	do {
		bool f = true;
		for (int i = 0; i < 3 && f; i++) {
			for (int j = 0; j < i; j++) {
				if (!(cmp(v[cur_perm[j]], v[cur_perm[i]]))) { f = false; break; }
			}
		}
		if (f) {
			cout << "yes\n"; return;
		}
	} while (next_permutation(cur_perm.begin(), cur_perm.end()));
	cout << "no\n";
}

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	int T; std::cin >> T;

	while (T--) {
		solve();
	}
}