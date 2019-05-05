// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

vector<int> adj[5005];
int num[5005];
bool disc[5005];

stack<int> st;

void dfs(int root) {
  st.push(root);
  while (!st.empty()) {
    int t = st.top();
    st.pop();
    if (disc[t]) continue;
    disc[t] = true;
    for (int v : adj[t]) {
      if (!disc[v]) st.push(v);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num[i];
    if (num[i] == 1) {
      cout << "1\n";
      return 0;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (__gcd(num[i], num[j]) == 1) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  int ccount = 0;

  for (int i = 0; i < N; i++) {
    if (!disc[i]) {
      ccount++;
      dfs(i);
    }
  }

  cout << ccount << '\n';
}
