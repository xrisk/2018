// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long LL;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<int> vec(n);

  priority_queue<int> even;
  priority_queue<int> odd;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vec[i] = x;
    if (x % 2 == 0)
      even.push(x);
    else
      odd.push(x);
  }

  // first was even

  LL val = 0;
  LL ret = INT_MAX;
  while (true) {
    if (even.size() == 0) {
      break;
    } else {
      even.pop();
    }
    if (odd.size() == 0) {
      break;
    } else {
      odd.pop();
    }
  }

  while (even.size() != 0) {
    val += even.top();
    even.pop();
  }
  while (odd.size() != 0) {
    val += odd.top();
    odd.pop();
  }

  ret = min(ret, val);

  for (auto x : vec) {
    if (x % 2 == 0)
      even.push(x);
    else
      odd.push(x);
  }

  val = 0;
  while (true) {
    if (odd.size() == 0) {
      break;
    } else {
      odd.pop();
    }
    if (even.size() == 0) {
      break;
    } else {
      even.pop();
    }
  }

  while (even.size() != 0) {
    val += even.top();
    even.pop();
  }
  while (odd.size() != 0) {
    val += odd.top();
    odd.pop();
  }

  ret = min(ret, val);

  cout << ret << '\n';
}
