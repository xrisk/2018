#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

typedef long long LL;
typedef long double LD;

using namespace std;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    LL N, sigma;
    cin >> N >> sigma;
    LL target = sigma * sigma * N;
    // cout << target << "\n";
    if (N == 1) {
      if (sigma == 0) {
        cout << "0\n";
      } else {
        cout << "-1\n";
      }
    } else {
      LD half = (LD)target / 2;
      LD one = sqrt(half);
      LD two = -one;
      cout << setprecision(18) << fixed << one << " " << two << " ";
      for (int i = 2; i < N; i++) cout << "0 ";
      cout << "\n";
    }
  }
}