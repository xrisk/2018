#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<pair<PII, LL> > vec;

  for (int i = 0; i < n; i++) {
    LL o;
    LL x;
    cin >> x;
    o = x;
    LL two = 0, three = 0;
    while (x % 2 == 0) {
      two++;
      x /= 2;
    }
    while (x % 3 == 0) {
      three++;
      x /= 3;
    }
    vec.push_back(make_pair(make_pair(two, -three), o));
  }

  sort(vec.begin(), vec.end());

  for (auto x : vec) {
    // cout << pow(2, x.first) * pow(3, -x.second) << ' ';
    cout << x.second << ' ';
  }
}