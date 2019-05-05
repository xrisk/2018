// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
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

  LL H, n;
  cin >> H >> n;

  vector<LL> vec(n);
  for (int i = 0; i < n; ++i) cin >> vec[i];

  LL r = 0;
  LL lowest = 0;
  for (auto x : vec) {
    r += x;
    if (r < lowest) lowest = r;
  }

  LL rtot = accumulate(vec.begin(), vec.end(), 0);

  // cout << lowest << ' ' << rtot << endl;
  if (rtot >= 0) {
    if (H + lowest <= 0) {
      for (int i = 0; i < n; i++) {
        H += vec[i];
        if (H <= 0) {
          cout << i + 1 << '\n';
          return 0;
        }
      }
    } else {
      cout << "-1\n";
    }
  } else {
    LL xx = rtot;
    if (xx < 0) xx *= -1;
    LL cnt = H / xx;
    if (H % xx != 0) cnt++;

    // cout << "cnt " << cnt << endl;

    LL solution = LLONG_MAX;

    for (LL foo = cnt; foo >= 1; --foo) {
      bool fl = false;
      LL H_tmp = H;
      if (foo != 0) H_tmp += (foo - 1) * rtot;

      // cout << foo << " " << H_tmp << endl;
      for (int i = 0; i < n; i++) {
        H_tmp += vec[i];
        if (H_tmp <= 0) {
          fl = true;
          solution = min(solution, ((foo - 1) * n) + i + 1);
          break;
        }
      }
      if (!fl) break;
    }
    cout << solution << '\n';
  }
}