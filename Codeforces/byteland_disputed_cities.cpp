#include <iostream>
#include <utility>
#include <vector>

typedef std::pair<int, char> city;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n;
  std::cin >> n;
  std::vector<city> vec;
  std::vector<int> purp;
  std::vector<int> blue;
  std::vector<int> red;

  for (int i = 0; i < n; i++) {
    int c;
    char t;
    std::cin >> c >> t;
    if (t == 'P') purp.push_back(i);
    city.push_back(std::make_pair(c, t));
  }

  int pcount = purp.size();

  if (pcount == 0) {
    int sol = 0;
    if (red.size() != 0) sol += red.back() - red.front();
    if (blue.size() != 0) sol += blue.back() - blue.front();
    std::cout << sol << '\n';
  } else {
    int sol = 0;
    for (int pc : purp) {
      if (pc == purp.front()) {
        sol += std::lower
      }
    }
  }
}