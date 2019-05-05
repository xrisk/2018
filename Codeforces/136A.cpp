#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n;
  cin >> n;

  vector<int> vec(n + 1);

  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    vec[t] = i;
  }

  for (int i = 1; i <= n; i++) {
    cout << vec[i] << " ";
  }

  cout << "\n";
}