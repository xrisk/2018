#include <iostream>
#include <queue>

using namespace std;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;
    if (N == 1) {
      cout << "NO\n";
      continue;
    }
    vector<int> vec(N);
    priority_queue<int> m;
    priority_queue<int> t;
    int req = 0;
    for (int i = 0; i < N; i++) {
      cin >> vec[i];
      if (i % 2 == 0) {
        m.push(vec[i]);
        req += vec[i];
      } else {
        t.push(-vec[i]);
        req -= vec[i];
      }
    }

    int swap = 0;
    while (swap < K && req >= 0) {
      int mtop, ttop;
      swap++;
      mtop = m.top();
      m.pop();
      ttop = -t.top();
      t.pop();
      if (ttop < mtop) {
        req -= 2 * abs(ttop - mtop);
      }
    }

    if (req < 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}