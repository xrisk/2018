// rishav.io

#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

constexpr int NMAX = 2e5 + 5;

int counts[NMAX];

bool p(vector<PII> &vec, int k, int target) {
  for (auto &p : vec) {
    if (p.first < target) break;
    k -= p.first / target;
    if (k <= 0) return true;
  }
  return false;
}

void gen(vector<PII> &vec2, int k, int soln) {
  for (auto &p : vec2) {
    if (k <= 0) break;
    for (int i = 0; i < p.first / soln; i++) {
      cout << p.second << ' ';
      k--;
      if (k == 0) break;
    }
  }
  // cout << k << '\n';
  assert(k == 0);
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;
  set<int> vec;
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    vec.insert(s);
    counts[s]++;
  }

  vector<pair<int, int>> vec2;

  for (int x : vec) {
    vec2.push_back({counts[x], x});
  }

  sort(vec2.begin(), vec2.end(), greater<pair<int, int>>());
  // int sz = vec2.size();

  // for (auto &p : vec2) {
  // 	cout << p.first << ' ' << p.second << '\n';
  // }

  int lo = 1;
  int hi = vec2[0].first + 1;

  // cout << lo << ' ' << hi << '\n';

  for (int i = hi; i >= lo; i--) {
    if (p(vec2, k, i)) {
      // cout << i << '\n';
      gen(vec2, k, i);
      return 0;
    }
  }

  // while (lo < hi) {
  // 	int mid = lo + (hi - lo + 1) / 2;
  // 	// cout << mid << ' ' << lo << ' ' << hi << '\n';
  // 	if (p(vec2, k, mid)) {
  // 		lo = mid;
  // 	} else {
  // 		hi = mid - 1;
  // 	}
  // }

  // LL soln = lo;
}
