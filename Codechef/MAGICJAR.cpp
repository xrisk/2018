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
    int N;
    cin >> N;
    LL sol = 0;
    while (N--) {
      LL x;
      cin >> x;
      sol += (x - 1);
    }
    cout << sol + 1 << '\n';
  }
}
