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

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    set<char> look;
    bool fl = true;
    for (char c : s) {
      if (look.find(c) != look.end()) {
        fl = false;
        break;
      }
    }
    if (!fl) {
      cout << "No\n";
      continue;
    }
    sort(s.begin(), s.end());
    for (int i = 1; i < (int)s.size(); i++) {
      if (s[i] != s[i - 1] + 1) {
        fl = false;
        break;
      }
    }
    if (fl) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}