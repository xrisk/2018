#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n;
  std::cin >> n;
  std::vector<int> vec(n);
  std::vector<pair<int, int> > segments;
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    if (i > 0)
      segments.push_back(
          make_pair(vec[i] - vec[i - 1], (i == 1 || i == n - 1) ? 1 : 0));
  }
  sort(segments.begin(), segments.end());
  reverse(segments.begin(), segments.end());

  pair<int, int> p = segments[0];
  if (p.second == 1) {
    if (segments[1].first % 2 == 0)
      segments[1].first /= 2;
    else
      segments[1].first = segments[1].first / 2 + 1;
    segments[0] = make_pair(0, 0);
  } else {  // move the point to the midpoint
    if (segments[0].first % 2 == 0)
      segments[0].first /= 2;
    else
      segments[0].first = segments[0].first / 2 + 1;
  }

  cout << (*max_element(segments.begin(), segments.end())).first << '\n';
}