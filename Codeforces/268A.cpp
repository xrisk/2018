// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

int host_cnt[105];
int guest_cnt[105];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int h, g;
    cin >> h >> g;
    host_cnt[h]++;
    guest_cnt[g]++;
  }

  int cnt = 0;
  for (int i = 0; i <= 100; i++) {
    cnt += host_cnt[i] * guest_cnt[i];
  }
  cout << cnt << '\n';
}
