// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

void factorize(LL x, map<LL, LL> &fcnt) {
  LL div;
  for (div = 2; div <= (LL)sqrt(x); div++) {
    while (x % div == 0) {
      fcnt[div]++;
      x /= div;
    }
  }
  if (x > 1) fcnt[x]++;
}

bool pow2(LL x) {
  if (x == 0) return false;
  while (x != 1) {
    if (x % 2 != 0) return false;
    x /= 2;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  map<LL, LL> fcnt;
  LL x;
  cin >> x;

  if (x == 1) {
    cout << "1 0\n";
    return 0;
  }

  factorize(x, fcnt);

  LL highest = 1;

  for (auto &p : fcnt) {
    if (p.second > highest) highest = p.second;
  }

  LL flag = pow2(highest);
  LL bleh = false;

  if (flag) {
    for (auto &p : fcnt) {
      if (p.second != highest) bleh = true;
    }
  }

  LL opcount = 0;
  if (!flag || bleh) opcount++;

  // cout << opcount << '\n';

  if (!flag) {
    highest = highest << 1;
  }

  while (highest > 1) {
    opcount++;
    highest /= 2;
  }

  LL ans = 1;

  for (auto &p : fcnt) {
    ans *= p.first;
  }

  cout << ans << ' ' << opcount << '\n';
}
