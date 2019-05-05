// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

constexpr int NMAX = 1e5 + 1;

vector<vector<int>> adj;
vector<int> parent(NMAX);
vector<LL> vcost(NMAX);
LL X;

void dfs(int u) {
  for (int v : adj[u]) {
    if (v != parent[u]) {
      parent[v] = u;
      dfs(v);
    }
  }
}

LL solve(int u) {
  LL s = vcost[u];
  for (int v : adj[u]) {
    if (v != parent[u]) {
      s += solve(v);
    }
  }
  return max(s, -X);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N >> X;

    adj.clear();
    adj.resize(N + 1);

    fill(parent.begin(), parent.end(), 0);
    fill(vcost.begin(), vcost.end(), 0LL);
    // fill(dp.begin(), dp.end(), LLONG_MIN);

    for (int i = 0; i < N; i++) cin >> vcost[i];

    for (int i = 0; i < N - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    parent[0] = -1;
    dfs(0);

    cout << solve(0) << '\n';
  }
}