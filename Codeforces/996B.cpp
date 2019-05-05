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

  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];

  int min_el = *min_element(vec.begin(), vec.end());

  int cur_pos = min_el % n;
  int decay_amount = min_el;

  while (true) {
    if (vec[cur_pos] - decay_amount <= 0) {
      cout << cur_pos + 1 << '\n';
      return 0;
    }
    cur_pos = (cur_pos + 1) % n;
    decay_amount += 1;
  }
}