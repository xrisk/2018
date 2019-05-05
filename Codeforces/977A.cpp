#include <iostream>

using namespace std;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < k; i++) {
    if (n % 10 != 0)
      n--;
    else
      n /= 10;
  }
  cout << n << '\n';
}
