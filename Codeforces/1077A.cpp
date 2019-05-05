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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    LL a, b, k;
    cin >> a >> b >> k;
    LL diff = a - b;
    LL pos = diff * (k / 2);
    if (k % 2) pos += a;
    cout << pos << '\n';
  }
}
