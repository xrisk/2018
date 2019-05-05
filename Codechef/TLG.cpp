#include <iostream>

using namespace std;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int a = 0, b = 0;
  int N;
  cin >> N;
  int winner;
  int maxdiff = 0;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    a += x;
    b += y;
    // cout << a << ' ' << b << ' ' << abs(a - b) << '\n';
    if (a != b && abs(a - b) > maxdiff) {
      maxdiff = abs(a - b);
      winner = (a > b) ? 1 : 2;
    }
  }
  cout << winner << " " << maxdiff << '\n';
}