#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

typedef long long LL;

using namespace std;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  if (n == k) {
    cout << '\n';
    return 0;
  }

  vector<vector<int> > pos(26);
  vector<bool> cleared(26);
  vector<bool> tmp(s.size());

  for (int i = 0; i < (int)s.size(); i++) {
    char c = s[i];
    pos[c - 'a'].push_back(i);
  }

  for (int i = 0; i < 26; i++) {
    if ((int)pos[i].size() <= k) {
      cleared[i] = true;
      k -= pos[i].size();
    } else {
      for (int j = 0; j < k; j++) {
        tmp[pos[i][j]] = true;
      }
      k = 0;
      break;
    }
  }

  for (int i = 0; i < (int)s.size(); i++) {
    char c = s[i];
    if (cleared[c - 'a']) continue;
    if (tmp[i]) continue;
    cout << c;
  }
  cout << '\n';
}