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

  int a[4];
  for (int i = 0; i < 4; i++) cin >> a[i];

  string s;
  cin >> s;
  int res = 0;
  for (char c : s) {
    int d = c - '0';
    res += a[d - 1];
  }
  cout << res << '\n';
}
