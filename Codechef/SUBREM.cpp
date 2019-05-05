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

vector<vector<int>> adj;
vector<int> vertex;
vector<int> parent;
vector<LL> cost;

void dfs(int x, int p) {
  if (parent[x] != 0) return;
  parent[x] = p;
  for (auto v : adj[x]) {
    if (v != p) dfs(v, x);
  }
}

void dfs2(int x, set<int> &used, bool f) {
  auto foo = used.insert(x);
  if (f == false && foo.second == false) return;
  // cout << "dfs2 -> " << x << '\n';
  for (auto v : adj[x]) {
    // cout << v << endl;
    if (v != parent[x]) dfs2(v, used, false);
  }
}

LL compute_cost(int x) {
  LL ret = vertex[x];
  for (auto v : adj[x]) {
    if (v != parent[x]) ret += compute_cost(v);
  }
  cost[x] = ret;
  return ret;
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
    vertex.clear();
    adj.clear();
    parent.clear();
    cost.clear();

    int N, X;
    cin >> N >> X;

    // if (N > 1000) return 1;
    vertex.resize(N + 1);
    adj.resize(N + 1);
    parent.resize(N + 1);
    cost.resize(N + 1);

    for (int i = 1; i <= N; i++) cin >> vertex[i];

    for (int i = 0; i < N - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(1, 0);
    compute_cost(1);

    set<pair<LL, LL>> s;
    set<int> used;
    for (int i = 1; i <= N; i++) s.insert({cost[i], i});

    LL best_so_far = cost[1];
    LL current_value = cost[1];
    LL k = 0;

    for (auto p : s) {
      // for (auto q : used) {
      // 	cout << q << ' ';
      // }
      // cout << "\n-----------\n";
      if (used.find(p.second) != used.end()) continue;
      k++;
      current_value -= p.first;
      LL tmp = p.second;
      while (tmp != 0) {
        auto oo = used.insert(tmp);
        if (oo.second == false) break;
        tmp = parent[tmp];
      }
      // cout << p.second << '\n';
      dfs2(p.second, used, true);
      LL cur = current_value - X * k;
      if (tmp > best_so_far) best_so_far = cur;
    }

    cout << best_so_far << '\n';
  }
}