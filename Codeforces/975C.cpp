#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  LL n, q;
  cin >> n >> q;

  vector<LL> str(n);

  for (int i = 0; i < n; i++) cin >> str[i];

  vector<LL> cf(n);
  for (int i = 0; i < n; i++) {
    if (i == 0)
      cf[i] = str[i];
    else
      cf[i] = cf[i - 1] + str[i];
  }

  LL rem = 0;

  for (int i = 0; i < q; i++) {
    LL attack;
    cin >> attack;
    auto it = lower_bound(cf.begin(), cf.end(), attack + rem);
    // cout << "Attack + rem" << " " << attack + rem << '\n';
    LL ded = 0;
    if (*it == (attack + rem))
      ded = it - cf.begin() + 1;
    else
      ded = it - cf.begin();
    // cout << i + 1 << " ded " << ded << '\n';
    if (ded == n) {
      // cout << i + 1 << " thooor\n";
      cout << n << '\n';

      rem = 0;
    } else {
      cout << n - ded << '\n';
      rem += attack;
    }
  }
}