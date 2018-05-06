#include <iostream>
#include <vector>

using namespace std;

constexpr int NMAX = 2e5 + 1;

typedef long long LL;

vector< vector<int> > adj;
vector<bool> vis;
vector< int > clist[NMAX];

void dfs(int u, int comp) {
	if (vis[u]) return;
	vis[u] = true;
	clist[comp].push_back(u);
	for (LL v : adj[u]) {
		dfs(v, comp);
	}
}

int dfs_check(int u) {
	int ctr = 0;
	if (vis[u]) return 0;

	vis[u] = true;
	for (LL v : adj[u]) {
		ctr += dfs_check(v);
		ctr++;
	}
	return ctr;
}

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	int n, m; cin >> n >> m;
	adj.resize(n + 1);
	vis.resize(n + 1);


	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ccont = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs(i, ccont++);
	}

	// cout << "ccnt " << ccont << '\n';
	fill(vis.begin(), vis.end(), false);
	
	int sol = 0;
	for (int i = 0; i < ccont; i++) {
	
		if (clist[i].size() <= 2) continue;

		bool fl = true;
		for (int u : clist[i]) {
			if (adj[u].size() != 2) { fl = false; break; }
		}

		if (fl) sol++;
	}

	cout <<  sol << '\n';


}