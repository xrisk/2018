#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int N, H;
  cin >> N >> H;
  vector<int> vec(N);

  for (int i = 0; i < N; i++) {
    cin >> vec[i];
  }

  int idx = 0;
  int state = 0;
  while (1) {
    int op;
    cin >> op;
    if (op == 1) idx = max(0, idx - 1);
    if (op == 2) idx = min(N - 1, idx + 1);
    if (op == 3) {
      if (state == 0 && vec[idx] != 0) {
        state = 1;
        vec[idx]--;
      }
    }
    if (op == 4) {
      if (state == 1 && (vec[idx] + 1 <= H)) {
        state = 0;
        vec[idx]++;
      }
    }
    if (op == 0) break;
  }
  for (int i = 0; i < N; i++) {
    cout << vec[i] << ' ';
  }
  cout << '\n';
}