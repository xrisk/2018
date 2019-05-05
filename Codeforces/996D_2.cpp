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
  vector<int> vec(2 * n);

  for (int i = 0; i < 2 * n; i++) {
    cin >> vec[i];
  }

  int best = INT_MAX;
  int bestnum = -1;
  for (int i = 1; i <= n; i++) {
    int one = find(vec.begin(), vec.end(), i) - vec.begin();
    int two = find(vec.begin() + one, vec.end(), i) - vec.begin();
  }
}