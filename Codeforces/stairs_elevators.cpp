#include <limits.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  LL n, m, cl, ce, v;
  cin >> n >> m >> cl >> ce >> v;

  vector<int> stairs(cl);
  vector<int> elev(ce);
  for (int i = 0; i < cl; i++) cin >> stairs[i];
  for (int i = 0; i < ce; i++) cin >> elev[i];

  sort(stairs.begin(), stairs.end());
  sort(elev.begin(), elev.end());

  int q;
  cin >> q;

  while (q--) {
    LL x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector<LL> stairpos;
    if (cl != 0) {
      auto a = lower_bound(stairs.begin(), stairs.end(), y1);
      if (a != stairs.end()) stairpos.push_back(*a);
      if (a != stairs.begin()) {
        stairpos.push_back(*(a - 1));
      }
    }

    vector<LL> elevpos;
    if (ce != 0) {
      auto a = lower_bound(elev.begin(), elev.end(), y1);
      if (a != elev.end()) elevpos.push_back(*a);
      if (a != elev.begin()) {
        elevpos.push_back(*(a - 1));
      }
    }

    LL mincost = LLONG_MAX;
    for (LL x : stairpos) {
      LL cost = abs(x2 - x1);
      cost += abs(x - y1);
      cost += abs(x - y2);
      mincost = min(mincost, cost);
    }

    for (LL x : elevpos) {
      LL cost = ceil(abs(x2 - x1) / (double)v);
      cost += abs(x - y1);
      cost += abs(x - y2);
      mincost = min(mincost, cost);
    }

    if (x1 == x2) {
      mincost = abs(y1 - y2);
    }

    cout << mincost << '\n';
  }
}
