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

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < k; i++) {
    cout << (char)('a' + i);
  }

  char last = 'a' + (k - 1);

  for (int i = 0; i < n - k; i++) {
    if (i % 2 == 0) {
      last--;
      cout << (char)last;
    } else {
      last++;
      cout << (char)last;
    }
  }

  cout << '\n';
}
