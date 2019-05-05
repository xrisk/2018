// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>}
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

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    LL N;
    cin >> N;
    vector<LL> runs;
    string s;
    cin >> s;
    string X;
    cin >> X;

    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == X[0])
        s[i] = '1';
      else
        s[i] = '0';
    }

    char last = s[0];
    int cur_len = 1;

    for (int i = 1; i < (int)s.size(); i++) {
      if (s[i] == last)
        cur_len++;
      else {
        if (last == '0') runs.push_back(cur_len);
        last = s[i];
        cur_len = 1;
      }
    }

    if (cur_len != 0 && last == '0') runs.push_back(cur_len);

    LL sol = N * (N + 1) / 2;
    for (auto p : runs) {
      sol -= p * (p + 1) / 2;
    }
    cout << sol << '\n';
  }
}