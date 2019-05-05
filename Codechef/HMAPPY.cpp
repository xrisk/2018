// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

typedef long long LL;

using namespace std;

LL req(LL mid, vector<LL> &b, vector<LL> &c, LL M) {
  LL s = 0;
  for (int i = 0; i < (int)b.size(); i++) {
    LL tmp = b[i] * c[i];
    if (tmp > mid) {
      LL diff = (tmp - mid);
      LL t = (diff / c[i]);
      if ((diff % c[i]) != 0) t++;
      s += min(b[i], t);
    }
  }
  // cout << mid << " => " << s << '\n';
  return s <= M;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  LL N, M;
  cin >> N >> M;

  vector<LL> balloons(N);

  for (int i = 0; i < N; i++) cin >> balloons[i];

  vector<LL> candies(N);

  for (int i = 0; i < N; i++) {
    cin >> candies[i];
  }

  LL lo = 0;
  LL hi = static_cast<LL>(1e18) + 5;

  while (lo < hi) {
    LL mid = (lo + hi) / 2;
    // cout << "mid => " << mid  << '\n';
    if (req(mid, balloons, candies, M)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  cout << lo << '\n';
}