#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

typedef long long LL;

using namespace std;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;

  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      reverse(s.begin(), s.begin() + i);
    }
  }

  cout << s << '\n';
}