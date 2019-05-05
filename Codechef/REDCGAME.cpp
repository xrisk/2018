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

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;

    vector<int> a;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n - 1; i++) {
      if (a[i] <= k) continue;
      a[i + 1] -= (a[i] - k);
      a[i] = k;
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
      sum += a[i];
    }

    cout << sum << '\n';
  }
}
