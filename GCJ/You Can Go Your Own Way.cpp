// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long LL;

void solve() {
  int N;
  cin >> N;
  string P;
  cin >> P;
  for (char c : P) {
    if (c == 'E')
      cout << 'S';
    else
      cout << 'E';
  }
  cout << '\n';
}

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    solve();
    // cout << '\n';
  }
}