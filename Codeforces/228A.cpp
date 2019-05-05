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

  int s[4];
  for (int i = 0; i < 4; i++) cin >> s[i];

  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < i; j++) {
      if (s[i] == s[j] && s[j] != -1) {
        cnt++;
        s[i] = -1;
      }
    }
  }
  cout << cnt << '\n';
}
