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

int longest(vector<int> &vec) {
  int longest = 0;
  int cur_length = 0;
  int last_elem = -1;

  for (auto x : vec) {
    if (x == 1) {
      if (last_elem != 1) {
        // starting a new block
        cur_length = 1;
      } else
        cur_length++;
    } else if (x == 0) {
      longest = max(longest, cur_length);
      cur_length = 0;
    }
    last_elem = x;
  }

  if (cur_length > 0) longest = max(longest, cur_length);
  return longest;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<int> vec(2 * n);

  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
    vec[n + i] = vec[i];
  }

  cout << longest(vec) << '\n';
}
