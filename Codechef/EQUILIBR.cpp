#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

constexpr int MOD = 1e9 + 7;

LL power(int a, int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  LL tmp = power(a, b / 2);
  LL sq = (tmp * tmp) % MOD;
  if (b % 2 == 0)
    return sq;
  else
    return (a * sq) % MOD;
}

int mmi(int a) { return power(a, MOD - 2); }

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> N;
    int num = n;
    int denum = pow(2, num - 1);
  }
}