// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    if (s.size() <= 10)
      cout << s << '\n';
    else {
      cout << s[0];
      cout << (int)s.size() - 2;
      cout << s.back() << '\n';
    }
  }
}
