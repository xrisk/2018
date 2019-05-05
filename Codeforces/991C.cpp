#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

typedef long long LL;

using namespace std;

bool p(LL mid, LL init) {
  LL one = 0;
  LL two = 0;
  LL total = init;
  // cout << mid << "\n";
  while (total > 0) {
    if (mid > total) {
      one += total;
      total = 0;
    } else {
      one += mid;
      total -= mid;
    }
    two += total / 10;
    // if (mid == 216) cout << "REKT " << one << " " << two << "\n";
    if (one * 2 >= (init)) return true;
    if (two * 2 > init) return false;
    total = total - total / 10;
  }
  return false;
}

bool full_eval(LL mid, LL init) {
  LL t = init;
  LL one = 0;
  LL two = 0;
  while (t > 0) {
    if (mid > t) {
      one += t;
      t = 0;
    } else {
      one += mid;
      t -= mid;
    }
    two += t / 10;
    // cout << "FULL_EVAL " << one << " " << two << "\n";
    t = t - t / 10;
  }

  return (one * 2) >= init;
}

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  LL n;
  cin >> n;
  LL lo = 1;
  LL hi = n;

  while (lo < hi) {
    LL mid = lo + (hi - lo) / 2;
    // cout << "lo " << lo << " " << hi << " mid " << mid << "\n";
    if (p(mid, n)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  // cout << "LO" << lo << "\n";
  for (int i = 1; i < lo; i++) {
    // cout << "asserting " << i << "\n";
    if (full_eval(i, n) == true) {
      // cout << i << "\n";
      cout << "FAILED\n";
      return 0;
    }
  }
  cout << (full_eval(lo, n) ? "PASSED " : "FAILED ") << "\n";
  // cout << lo << "\n";
}