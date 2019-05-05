// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long LL;

LL vec[40];

void show(int hash) {
  if (hash & 1) cout << 'a';
  if (hash & 2) cout << 'e';
  if (hash & 4) cout << 'i';
  if (hash & 8) cout << 'o';
  if (hash & 16) cout << 'u';
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    fill(vec, vec + 40, 0);

    LL N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
      string tmp;
      cin >> tmp;

      vector<bool> check(5);
      int cnt = 0;

      for (char c : tmp) {
        if (cnt == 5) break;
        if (check[0] == false && c == 'a') {
          check[0] = true;
          cnt++;
        } else if (check[1] == false && c == 'e') {
          check[1] = true;
          cnt++;
        } else if (check[2] == false && c == 'i') {
          check[2] = true;
          cnt++;
        } else if (check[3] == false && c == 'o') {
          check[3] = true;
          cnt++;
        } else if (check[4] == false && c == 'u') {
          check[4] = true;
          cnt++;
        }
      }

      int hash = 0;
      if (check[0]) hash |= (1 << 0);
      if (check[1]) hash |= (1 << 1);
      if (check[2]) hash |= (1 << 2);
      if (check[3]) hash |= (1 << 3);
      if (check[4]) hash |= (1 << 4);
      vec[hash]++;
    }

    LL ret = 0;
    for (int i = 0; i < 32; ++i) {
      if (vec[i] == 0) continue;
      if (i == 31) {
        ret += vec[i] * (N - 1);
      } else {
        LL complement = ((1 << 5) - 1) ^ i;

        LL sum = 0;
        for (int j = 1; j < 32; ++j) {
          if ((complement & j) >= complement) sum += vec[j];
        }
        // cout << vec[i] << ' ' << sum << '\n';
        ret += vec[i] * sum;
      }
    }

    cout << ret / 2 << '\n';

    // for (auto &p : m) {
    // 	cout << p.first << ' ' << p.second << '\n';
    // }
  }
}
