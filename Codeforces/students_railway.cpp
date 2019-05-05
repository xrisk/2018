#include <iostream>
#include <vector>

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n, a, b;
  std::cin >> n >> a >> b;
  std::string s;
  std::cin >> s;
  std::vector<int> runs;
  int lc = '*', rl = 0;
  for (char c : s) {
    if (c == '.') {
      rl++;
    } else if (c == '*') {
      if (lc == '.') {
        runs.push_back(rl);
        rl = 0;
      }
    }
    lc = c;
  }
  if (rl != 0) runs.push_back(rl);

  int sol = 0;
  for (int r : runs) {
    sol += std::min(a, r / 2);
    a -= std::min(a, r / 2);

    sol += std::min(b, r / 2);
    b -= std::min(b, r / 2);

    if (r % 2 == 1) {
      if (a >= b && a != 0) {
        a--;
        sol++;
      } else if (b != 0) {
        b--;
        sol++;
      }
    }
  }

  std::cout << sol << '\n';
}