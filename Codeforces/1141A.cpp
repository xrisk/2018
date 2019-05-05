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

int count(int x, int f) {
  int r = 0;
  while (x % f == 0) {
    r++;
    x /= f;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  int two1 = count(n, 2);
  int two2 = count(m, 2);

  int three1 = count(n, 3);
  int three2 = count(m, 3);

  int val = two2 - two1 + three2 - three1;
  while (two1 < two2) {
    n *= 2;
    two1++;
  }
  while (three1 < three2) {
    n *= 3;
    three1++;
  }

  if (n == m)
    cout << val << '\n';
  else
    cout << "-1\n";
}
