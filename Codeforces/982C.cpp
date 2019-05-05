#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > adj;
vector<bool> visited;

int soln = 0;

int dfs(int u) {
  int sz = 0;
  visited[u] = true;
  for (int v : adj[u]) {
    if (!visited[v]) {
      int r = dfs(v);
      if (r % 2 == 0) {
        soln++;
      } else {
        sz += r;
      }
    }
  }

  return sz + 1;
}

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  adj.resize(n + 1);
  visited.resize(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (dfs(1) % 2 == 0) {
    cout << soln << "\n";
  } else {
    cout << "-1\n";
  }
}