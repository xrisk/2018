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

  int n;
  cin >> n;
  string s;
  cin >> s;
  int a = 0, d = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A')
      a++;
    else
      d++;
  }

  if (a == d)
    cout << "Friendship";
  else if (a > d)
    cout << "Anton";
  else
    cout << "Danik";
  it
}
