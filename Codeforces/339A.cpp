// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  vector<int> vec;

  while (true) {
    int x;
    cin >> x;
    if (cin.eof()) break;
    vec.push_back(x);
    cin.ignore('1', '+');
  }

  int cnt = vec.size();
  sort(vec.begin(), vec.end());
  for (int i = 0; i < cnt - 1; i++) cout << vec[i] << '+';
  cout << vec[cnt - 1] << '\n';
}
