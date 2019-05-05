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
vector<LL> v(NMAX);
vector<LL> m(NMAX);
set<int> leaf;

void dfs(int u) {
  int c = 0;
  for (int v : adj[u]) {
    if (v != parent[u]) {
      parent[v] = u;
      c++;
      dfs(v);
    }
  }
  if (c == 0) leaf.insert(u);
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
    cin >> N;

    adj.clear();
    adj.resize(N + 1);

    leaf.clear();
    fill(parent.begin(), parent.end(), 0);
    fill(v.begin(), v.end(), 0);
    fill(m.begin(), m.end(), 0);
    fill(parent.begin(), parent.end(), 0);

    for (int i = 0; i < N - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    for (int i = 0; i < N; i++) cin >> v[i];
    for (int i = 0; i < N; i++) cin >> m[i];

    parent[0] = -1;
    dfs(0);

    for (auto p : leaf) {
      // cout << "leaf " << p << endl;
      LL g = -1;
      int tmp = p;
      while (tmp != -1) {
        if (g == -1)
          g = v[tmp];
        else
          g = __gcd(g, v[tmp]);
        tmp = parent[tmp];
      }
      LL ret = m[p] - __gcd(m[p], g);
      ret = (ret + m[p]) % m[p];
      cout << ret << ' ';
    }

    cout << '\n';
  }
}