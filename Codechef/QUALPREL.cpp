// rishav.io

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end(), greater<int>());
    int val = vec[K - 1];
    // cout << val << '\n';
    reverse(vec.begin(), vec.end());
    cout << N - (lower_bound(vec.begin(), vec.end(), val) - vec.begin())
         << '\n';
  }
}
