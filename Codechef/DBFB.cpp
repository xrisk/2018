#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

constexpr int NMAX = 1e5 + 5;
constexpr int MOD = 1e9 + 7;

int fib[NMAX];

void calc_fib() {
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < NMAX; i++) {
    LL t = (fib[i - 1] + fib[i - 2]) % MOD;
    fib[i] = t;
  }

  // for (int i = 0; i < 10; i++)
  // 	cout << fib[i] << ' ';
  // cout << '\n';
}

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  calc_fib();
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int M, N;
    cin >> M >> N;
    LL s_x = 0, s_y = 0;
    for (int i = 0; i < M; i++) {
      LL t;
      cin >> t;
      s_x = (s_x + t) % MOD;
    }
    for (int i = 0; i < M; i++) {
      LL t;
      cin >> t;
      s_y = (s_y + t) % MOD;
    }
    int A, B;

    if (N == 1) {
      A = 1;
      B = 0;
    } else if (N == 2) {
      A = 0;
      B = 1;
    } else {
      A = fib[N - 2];
      B = fib[N - 1];
    }
    // cout << A << ' ' << B << '\n';
    LL tmp1 = (A * s_x) % MOD;
    LL tmp2 = (B * s_y) % MOD;
    LL tmp3 = (tmp1 + tmp2) % MOD;
    LL ret = (M * tmp3) % MOD;
    cout << ret << '\n';
  }
}