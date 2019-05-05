#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

typedef long long LL;
using namespace std;

vector<int> vec;

// void pvec(vector<int> &vec) {
// 	cout << "{ ";
// 	for (int x : vec) {
// 		cout << x << ", ";
// 	}
// 	cout << " } ";
// }

int solve(int start) {
  // cout << "start -> " << start << '\n';

  if (start >= (int)vec.size()) return 0;
  if (vec[start] == vec[start + 1]) return solve(start + 2);

  vector<int> cpy(vec.begin(), vec.end());

  // first try replacing elem `start` with elem at `start + 1`
  int other_pos =
      find(vec.begin() + start + 2, vec.end(), vec[start + 1]) - vec.begin();
  int cnt1 = 0, cnt2 = 0;

  // if (start == 0) {
  // 	pvec(vec); cout << "one other_pos = " << other_pos << "\n";
  // }

  for (int i = other_pos - 1; i >= (start + 2); i--) {
    swap(vec[i], vec[i + 1]);
    cnt1++;
  }

  swap(vec[start], vec[start + 1]);
  swap(vec[start + 1], vec[start + 2]);
  cnt1 += 2;

  // if (start == 0) {
  // 	pvec(vec);
  // 	cout << "two\n";
  // }

  int sol1 = cnt1 + solve(start + 2);
  vec.assign(cpy.begin(), cpy.end());

  // then try replacing elem `start + 1` with elem at `start`

  other_pos =
      find(vec.begin() + start + 2, vec.end(), vec[start]) - vec.begin();

  for (int i = other_pos - 1; i >= (start + 1); i--) {
    swap(vec[i], vec[i + 1]);
    cnt2++;
  }

  // if (start == 0) {
  // 	pvec(vec);
  // 	cout << "three\n";
  // 	// cout << "foo " << other_pos << '\n';
  // }

  int sol2 = cnt2 + solve(start + 2);

  cout << start << ' ' << sol1 << ' ' << sol2 << '\n';
  return min(sol1, sol2);
}

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vec.resize(2 * n);

  for (int i = 0; i < 2 * n; i++) cin >> vec[i];

  cout << solve(0) << '\n';
}