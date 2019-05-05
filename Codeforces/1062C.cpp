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

constexpr int PREMAX = 1e5 + 2;
constexpr int MOD = 1e9 + 7;

LL pre[PREMAX];
LL poww2[PREMAX];

void foob() {
  pre[0] = 0;
  LL cur = 1;
  for (int i = 1; i < PREMAX; i++) {
    pre[i] = (pre[i - 1] + cur) % MOD;
    cur = (cur * 2) % MOD;
  }
}

void pre2() {
  poww2[0] = 1;
  for (int i = 1; i < PREMAX; i++) {
    poww2[i] = (poww2[i - 1] * 2) % MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  foob();
  pre2();

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n, q;
  cin >> n >> q;

  vector<LL> vec(n);

  // cout << poww2[10000] << '\n';

  string s;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      vec[i] = 0;
    else
      vec[i] = 1;
  }

  vector<LL> zero(n);
  vector<LL> one(n);

  if (vec[0] == 0)
    zero[0] = 1;
  else
    zero[0] = 0;

  one[0] = vec[0];

  for (int i = 1; i < n; i++) {
    zero[i] = zero[i - 1];
    one[i] = one[i - 1] + vec[i];
    if (vec[i] == 0) zero[i]++;
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    LL zero_cnt = zero[r];
    if (l != 0) zero_cnt -= zero[l - 1];
    LL one_cnt = one[r];
    if (l != 0) one_cnt -= one[l - 1];

    // cout << zero_cnt << ' ' << one_cnt << '\n';
    // cout << "kek\n";
    if (one_cnt == 0) {
      cout << "0\n";
      continue;
    } else {
      LL last = poww2[one_cnt - 1];
      LL sol = pre[one_cnt];
      last = (2 * last - 1) % MOD;
      while (last < 0) last += MOD;
      sol += (last * pre[zero_cnt]) % MOD;
      cout << sol % MOD << '\n';
    }
  }
}
