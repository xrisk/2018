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

  int k, n;
  cin >> k >> n;
  string s;
  cin >> s;
  sort(s.begin(), s.end());

  int weight = 0;
  char last = 'a';
  for (int i = 0; i < k && n > 0; i++) {
    if (i == 0) {
      weight += s[i] - 'a' + 1;
      last = s[i];
      // cout << s[i];
      n--;
    } else {
      if (s[i] - last <= 1) continue;
      weight += s[i] - 'a' + 1;
      last = s[i];
      // cout << s[i];
      n--;
    }
  }
  if (n == 0)
    cout << weight << '\n';
  else
    cout << "-1\n";
}