// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
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

  string a, b;
  cin >> a >> b;

  for (int i = 0; i < static_cast<int>(min(a.size(), b.size())); i++) {
    if (toupper(a[i]) < toupper(b[i])) {
      cout << "-1\n";
      return 0;
    } else if (toupper(a[i]) > toupper(b[i])) {
      cout << "1\n";
      return 0;
    }
  }

  if (a.size() < b.size())
    cout << "-1\n";
  else if (b.size() > a.size())
    cout << "1\n";
  else
    cout << "0\n";
}
