#include <limits.h>
#include <math.h>
#include <iostream>

using namespace std;
#define LL unsigned long long

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  LL n, k, M, D;
  cin >> n >> k >> M >> D;
  LL ans = 0;

  for (LL i = D; i >= 1; i--) {
    LL lower = n / (i * k);
    LL upper;
    if (i == 1)
      upper = LLONG_MAX;
    else if (n % (k * (i - 1)) == 0)
      upper = n / (k * (i - 1)) - 1;
    else
      upper = n / (k * (i - 1));
    LL x = upper;
    x = min(x, M);

    cout << lower << ' ' << upper << '\n';
    // cout << lower << ' ' << upper << '\n';

    if (x > M || x < lower) continue;
    ans = max(ans, i * x);
  }

  cout << ans << '\n';
}