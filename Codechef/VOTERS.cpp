#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  map<int, int> counter;

  int N[3];
  cin >> N[0] >> N[1] >> N[2];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < N[i]; j++) {
      int x;
      cin >> x;
      counter[x]++;
    }
  }

  vector<int> ret;
  for (auto it = counter.begin(); it != counter.end(); ++it) {
    if (it->second >= 2) ret.push_back(it->first);
  }
  cout << ret.size() << '\n';
  for (int i : ret) cout << i << '\n';
}