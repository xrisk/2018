// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
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

  LL N, M, K, L;
  cin >> N >> M >> K >> L;
  LL tmp = K + L;

  if (tmp > N) {
    cout << "-1\n";
    return 0;
  }

  if (tmp % M != 0) {
    tmp += (M - (tmp % M));
  }

  LL cnt = tmp / M;
  // cout << cnt << '\n';

  if ((cnt * M) > N) {
    cout << "-1\n";
  } else {
    cout << cnt << '\n';
  }
}
