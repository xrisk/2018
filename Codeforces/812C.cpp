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
typedef pair<int, int> PII;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n, S;
  cin >> n >> S;
  vector<PII> prices(n);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    prices[i] = {x, i + 1};
  }

  int lo = 0;
  int hi = n + 1;

  while (lo < hi) {
    int mid = (lo + hi) / 2;
  }
}
