// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

vector<int> adj[55];
vector<int> vec(55);

bool disc[55];

void init() {
  for (int i = 0; i < 55; i++) {
    adj[i].clear();
  }
  fill(disc, disc + 55, 0);
}

int dfs(int u) {
  if (disc[u]) return 0;
  disc[u] = true;
  int s = 0;
  for (int v : adj[u]) {
    s += dfs(v);
  }
  return 1 + s;
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
    init();

    int N;
    cin >> N;

    int cnt47 = 0;
    for (int i = 0; i < N; i++) {
      cin >> vec[i];
      if (vec[i] == 47) cnt47++;
    }

    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (__gcd(vec[i], vec[j]) == 1) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    if (dfs(0) == N) {
      cout << "0\n";
      for (int i = 0; i < N; i++) {
        cout << vec[i] << ' ';
      }
      cout << "\n";
    } else {
      cout << "1\n";
      if (cnt47 == N) {
        cout << "43 ";
        for (int i = 1; i < N; i++) cout << "47 ";
        cout << '\n';
      } else {
        cout << "47 ";
        for (int i = 1; i < N; i++) {
          cout << vec[i] << ' ';
        }
        cout << '\n';
      }
    }
  }
}
