// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
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

  int T;
  cin >> T;
  while (T--) {
    LL N, A, B, K;
    cin >> N >> A >> B >> K;
    LL ret = 0;
    ret += N / A;
    ret += N / B;
    ret -= 2 * (N / ((A * B) / __gcd(A, B)));
    if (ret >= K)
      cout << "Win\n";
    else
      cout << "Lose\n";
  }
}
