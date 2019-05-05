// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  string s, t;
  cin >> s >> t;
  int cur = 0;

  for (char c : t) {
    if (s[cur] == c) cur++;
  }

  cout << cur + 1 << '\n';
}
