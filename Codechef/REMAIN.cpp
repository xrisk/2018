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

  int T;
  cin >> T;
  while (T--) {
    LL N, M;
    cin >> N >> M;
    if (N % M % 2 == 0)
      cout << "EVEN\n";
    else
      cout << "ODD\n";
  }
}