#include <limits.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int hcf(int a, int b) {
  if (a > b) return hcf(b, a);
  if (a == 0) return b;
  return hcf(b % a, a);
}

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;
    int h = 0;
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      if (i == 0)
        h = x;
      else
        h = hcf(h, x);
    }
    if (h == 1)
      cout << "0\n";
    else
      cout << "-1\n";
  }
}