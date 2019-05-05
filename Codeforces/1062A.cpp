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
  vector<int> vec;
  vec.push_back(0);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vec.push_back(x);
  }

  vec.push_back(1001);

  int max_len = -1;

  for (int i = 0; i < (int)vec.size(); i++) {
    int len = 1;
    int cur = vec[i];
    for (int j = i + 1; j < (int)vec.size(); j++) {
      if (vec[j] != (cur + 1)) {
        break;
      } else {
        cur++;
        len++;
      }
    }
    max_len = max(max_len, len);
    // cout << i << " => " << len << '\n';
  }

  cout << max(0, max_len - 2) << '\n';
}
