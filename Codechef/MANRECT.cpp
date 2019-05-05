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

constexpr LL LIM = 1e9;

LL q(LL x, LL y) {
  cout << "Q " << x << ' ' << y << '\n';
  LL ret;
  cin >> ret;
  if (ret < 0)
    exit(0);
  else
    return ret;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(0);

  // #ifdef __APPLE__
  // 	freopen("input.txt", "r", stdin);
  // #endif

  int T;
  cin >> T;
  while (T--) {
    LL a = q(0, 0);
    LL b = q(LIM, 0);
    LL c = q(LIM, LIM);
    LL d = q(0, LIM);

    LL ledge = (a + (LIM - d)) / 2;
    LL redge = (b + (LIM - c)) / 2;
    LL bedge = (a + (LIM - b)) / 2;

    LL e = q(0, ledge);
    LL f = q(bedge, LIM);
    LL g = q(LIM, redge);

    LL xl = ledge;
    LL yl = ledge - d;

    cout << xl << ' ' << yl << '\n';
  }
}
