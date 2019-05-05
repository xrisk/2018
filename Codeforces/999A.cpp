#include <algorithm>
#include <climits>
#include <deque>
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

  int n, k;
  cin >> n >> k;
  deque<int> q;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    q.push_back(x);
  }

  int ctr = 0;
  while (!q.empty()) {
    if (q.front() <= k) {
      q.pop_front();
      ctr++;
    } else if (q.back() <= k) {
      q.pop_back();
      ctr++;
    } else
      break;
  }
  cout << ctr << '\n';
}