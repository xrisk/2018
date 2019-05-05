#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

#define int long long int

using namespace std;

main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int> > rem(m);
  vector<int> vec(n);
  vector<int> add(n);
  vector<int> sizes(m);

  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    rem[vec[i] % m].push_back(i);
  }

  for (int i = 0; i < m; i++) {
    sizes[i] = rem[i].size();
  }

  // for (int i = 0; i < m; i++) {
  // 		cout << i << " -> " << sizes[i] << '\n';
  // }

  int req = n / m;
  int sol = 0;

  for (int i = 0; i < m; i++) {
    if (sizes[i] > req) {
      int extra = sizes[i] - req;
      int next = (i + 1) % m;
      int start = req;

      while (extra > 0) {
        if (sizes[next] < req) {
          int tofill = req - sizes[next];
          for (int k = 0; k < tofill; k++) {
            vec[rem[i][start]] += (next - i + m) % m;
            sol += (next - i + m) % m;
            start++;
          }
          extra -= tofill;
          sizes[next] += tofill;
        }

        next = (next + 1) % m;
      }
    }
  }

  cout << sol << '\n';
  for (int i = 0; i < n; i++) cout << vec[i] << ' ';
  cout << '\n';
}