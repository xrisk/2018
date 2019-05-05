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
typedef pair<int, int> PII;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  string s;
  cin >> s;

  vector<pair<char, int>> vec;
  for (int i = 0; i < (int)s.size(); i++) {
    char c = s[i];
    if (c != 'a') vec.push_back({c, i});
  }

  // cout << vec.size() << endl;
  if (vec.size() == 0) {
    cout << s << "\n";
    return 0;
  }
  bool f = true;
  if (vec.size() % 2 != 0) {
    cout << ":(\n";
    return 0;
  }
  int half = vec.size() / 2;
  for (int i = 0; i < half; i++) {
    if (vec[i].first != vec[i + half].first) {
      f = false;
      break;
    }
  }
  if (!f) {
    cout << ":(\n";
    return 0;
  }

  int start = vec[half].second;
  for (int i = start; i < (int)s.size(); i++) {
    if (s[i] == 'a') {
      cout << ":(\n";
      return 0;
    }
  }

  cout << s.substr(0, start) << '\n';
}