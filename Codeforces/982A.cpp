#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (n == 1) {
    if (s[0] == '0')
      return false;
    else
      return true;
  }

  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '1' && s[i + 1] == '1') return false;
  }

  int ch = s[0];
  int len = 1;
  vector<pair<char, int> > groups;

  for (int i = 1; i < n; i++) {
    if (s[i] != ch) {
      groups.push_back(make_pair(ch, len));
      ch = s[i];
      len = 1;
    } else {
      len++;
    }
  }

  if (len != 0) {
    groups.push_back(make_pair(ch, len));
  }

  for (int i = 0; i < (int)groups.size(); i++) {
    if (i == 0 || (i == ((int)(groups.size()) - 1))) {
      if (groups[i].first == '0' && groups[i].second >= 2) return false;
    } else if (groups[i].first == '0' && groups[i].second >= 3)
      return false;
  }

  return true;
}

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  if (solve()) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}