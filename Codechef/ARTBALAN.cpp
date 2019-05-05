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

vector<int> factor(int x) {
  vector<int> ret;
  for (int i = 1; i <= x; ++i) {
    if (x % i == 0) ret.push_back(i);
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    string S;
    cin >> S;
    vector<int> freq(26);
    fill(freq.begin(), freq.end(), 0);
    for (char c : S) {
      freq[c - 'A']++;
    }
    int N = S.size();
    sort(freq.begin(), freq.end(), greater<int>());
    LL sol = INT_MAX;
    for (int x : factor(N)) {
      // cout << x << '\n';
      LL tmp = 0;
      int ngroup = N / x;
      if (ngroup > 26) break;
      for (int i = 0; i < ngroup; ++i) {
        if (freq[i] != 0 && freq[i] > x) tmp += freq[i] - x;
      }
      for (int i = ngroup; i < 26; ++i) {
        if (freq[i] != 0) tmp += freq[i];
      }
      cout << x << " => " << tmp << '\n';
      sol = min(sol, tmp);
    }
    cout << sol << '\n';
  }
}
