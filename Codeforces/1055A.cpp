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

  int n, s;
  cin >> n >> s;
  s--;
  vector<int> a(n);
  vector<int> b(n);

  for (int i = 0; i < n; i++) cin >> a[i];

  int sw = -1;

  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] == 1 && a[i] == 1) sw = i;
  }

  if (a[s] == 0 && b[s] == 0) {
    cout << "NO\n";
  } else if (a[0] == 0) {
    cout << "NO\n";
  } else if (a[0] == 1 && a[s] == 1) {
    cout << "YES\n";
  } else if (s <= sw) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
