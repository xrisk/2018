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

  int n, t, k, d;
  cin >> n >> t >> k >> d;

  int batches = n / k;
  if (n % k != 0) batches++;

  // cout << batches << '\n';

  int c1 = k * (d / t);
  // cout << "c1 -> " << c1 << '\n';
  if (c1 >= n) {
    cout << "NO\n";
    return 0;
  }
  if (batches - (d / t) == 1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
