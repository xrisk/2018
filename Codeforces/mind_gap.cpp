#include <iostream>

using namespace std;

int diff(int h1, int m1, int h2, int m2) {
  return abs((60 * h1 + m1) - ((60 * h2) + m2));
}

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n, s;
  cin >> n >> s;
  int cur_h = 0, cur_m = 0;

  for (int i = 0; i < n; i++) {
    int h, m;
    cin >> h >> m;
    int req_diff;
    if (i == 0)
      req_diff = s;
    else
      req_diff = 2 * s + 1;
    if (diff(cur_h, cur_m, h, m) > req_diff) {
      if (i == 0) {
        cout << "0 0\n";
        return 0;
      }
      cur_m += (s + 1);
      while (cur_m >= 60) {
        cur_h++;
        cur_m -= 60;
      }
      cout << cur_h << ' ' << cur_m << '\n';
      return 0;
    }
    cur_h = h, cur_m = m;
  }
  cur_m += (s + 1);
  while (cur_m >= 60) {
    cur_h++;
    cur_m -= 60;
  }
  cout << cur_h << ' ' << cur_m << '\n';
}