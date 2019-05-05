#include <limits.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> PII;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int N, x, y;
  cin >> N >> x >> y;
  vector<PII> contests(N);
  vector<int> X(x);
  vector<int> Y(y);
  for (int i = 0; i < N; i++) {
    int s, e;
    cin >> s >> e;
    contests[i] = make_pair(s, e);
  }
  for (int i = 0; i < x; i++) cin >> X[i];
  for (int i = 0; i < y; i++) cin >> Y[i];

  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());

  int answer = INT_MAX;
  for (int i = 0; i < N; i++) {
    int s = contests[i].first, e = contests[i].second;

    if (X[0] > contest[i].first)
      auto end_time = lower_bound(Y.begin(), Y.end(), e);
    auto start_time = upper_bound(X.begin(), X.end(), s);

    int cur = *(end_time) - *(start_time - 1) + 1;
    cout << cur << '\n';

    answer = min(answer, cur);
  }

  // cout << answer << '\n';
}