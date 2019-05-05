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

  int n;
  cin >> n;
  LL sum = 0;
  vector<int> vec(n);
  vector<int> vec2(n);

  int max_elem = -1;
  int max_cnt = -1;
  int max2 = -1;
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    sum += vec[i];
    if (vec[i] > max_elem) {
      max2 = max_elem;
      max_elem = vec[i];
      max_cnt = 1;
    } else if (vec[i] == max_elem) {
      max_cnt++;
    } else if (vec[i] > max2) {
      max2 = vec[i];
    }
  }

  // cout << max_elem << '\n';
  // cout << max_cnt << '\n';
  // cout << max2 << '\n';
  vector<int> sols;

  for (int i = 0; i < n; i++) {
    LL r = sum - vec[i];
    LL m = max_elem;
    if (vec[i] == max_elem && max_cnt == 1) m = max2;
    if ((r - m) == m) {
      sols.push_back(i + 1);
    }
  }

  cout << sols.size() << '\n';
  for (int x : sols) {
    cout << x << ' ';
  }
  cout << '\n';
}
