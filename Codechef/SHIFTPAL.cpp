#include <iostream>
#include <string>

using namespace std;

typedef long long LL;

const LL MOD = 1e9 + 87;
const LL NMAX = 4e5 + 5;
const LL POLY = 101;

LL pref[NMAX];
LL suf[NMAX];
LL ex[NMAX];

void calc_pows() {
  ex[0] = 1;
  for (int i = 1; i < NMAX; i++) {
    ex[i] = (ex[i - 1] * POLY) % MOD;
  }
}

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  calc_pows();
  int T;
  cin >> T;

  while (T--) {
    string s;
    cin >> s;
    s += s;

    int N = s.size();
    int cnt = 0;

    for (int i = 0; i < N; i++) {
      if (i == 0)
        pref[i] = ((s[i] - 'a') * ex[i]) % MOD;
      else
        pref[i] = (pref[i - 1] + ((s[i] - 'a') * ex[i]) % MOD) % MOD;

      if (i == 0)
        suf[N - i - 1] = ((s[i] - 'a') * ex[i]) % MOD;
      else
        suf[N - i - 1] = (suf[N - i] + ((s[i] - 'a') * ex[i]) % MOD) % MOD;
    }

    for (int i = 0; i < N / 2; i++) {
      int lo = i;
      int hi = N / 2 + i - 1;
      LL h1 = pref[hi];
      if (lo != 0) h1 -= pref[lo - 1];

      LL h2 = suf[lo];
      if (hi != N - 1) h2 -= suf[hi + 1];

      if (h1 < 0) h1 += MOD;
      if (h2 < 0) h2 += MOD;

      h1 = (h1 * ex[N - hi - 1]) % MOD;
      h2 = (h2 * ex[lo]) % MOD;

      // cout << lo << " " << hi << " :: " << h1 << " " << h2 << "\n";

      if (h1 == h2) cnt++;
    }

    cout << cnt << "\n";
  }
}