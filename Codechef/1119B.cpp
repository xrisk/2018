// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n, h;
vector<int> heights;

ostream& operator<<(ostream& o, vector<int>& x) {
  o << "{ ";
  for (auto p : x) o << p << ", ";
  o << "} ";
  return o;
}

bool p(int mid) {
  vector<int> r;
  for (int i = 0; i < mid; i++) {
    r.push_back(heights[i]);
  }
  sort(r.begin(), r.end(), greater<int>());
  int t = 0;
  for (int i = 0; i < (int)r.size(); i += 2) {
    t += r[i];
  }
  // if (mid == 3) cout << t << "LEL\n";
  return t <= h;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  cin >> n >> h;
  heights.resize(n);
  for (int i = 0; i < n; i++) cin >> heights[i];

  int lo = 1;
  int hi = n + 1;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    // cout << mid << endl;
    if (p(mid))
      lo = mid + 1;
    else
      hi = mid;
  }
  cout << lo - 1 << '\n';
}