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

  int n;
  cin >> n;
  string s;
  cin >> s;

  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) cnt++;
  }

  cout << cnt << '\n';
}
