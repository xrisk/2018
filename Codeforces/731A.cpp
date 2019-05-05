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

  string s;
  cin >> s;

  int cnt = 0;
  int last = 0;
  for (char c : s) {
    int cur = c - 'a';
    int diff = abs(cur - last);
    cnt += min(diff, 26 - diff);
    last = cur;
  }
  cout << cnt << '\n';
}
