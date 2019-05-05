#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n, A, B;
  cin >> n >> A >> B;
  vector<int> holes(n - 1);
  int h1;
  cin >> h1;
  int sum = h1;
  for (int i = 0; i < n - 1; i++) {
    cin >> holes[i];
    sum += holes[i];
  }
  sort(holes.begin(), holes.end(), greater<int>());
  double S = (double)(A * h1) / B;
  int idx = 0;
  while (sum > S) {
    sum -= holes[idx++];
  }
  cout << idx << '\n';
}