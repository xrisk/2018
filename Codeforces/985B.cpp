#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	int n, m; cin >> n >> m;
	vector<int> cnt(m);
	vector<vector<int> > adj(n);

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '1') {
				adj[i].push_back(j);
				cnt[j]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		bool f = true;
		for (int j : adj[i]) {
			if (cnt[j] == 1) { f = false; break; }
		}
		if (f) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
}