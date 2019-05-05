// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

void factorize(int x, map<int, int> &m) {
  int d = 2;
  while (x > 1) {
    while (x % d == 0) {
      m[d]++;
      x /= d;
    }
    d++;
  }
}

void divide(int x, map<int, int> &m) {
  int d = 2;
  while (x > 1) {
    while (x % d == 0) {
      m[d]--;
      x /= d;
    }
    d++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<int> digits;

  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    if (ch != 0) digits.push_back(ch - '0');
  }

  map<int, int> fcnt;

  for (int x : digits) {
    for (int i = 2; i <= x; i++) {
      factorize(i, fcnt);
    }
  }

  int primes[] = {7, 5, 3, 2};

  vector<int> res;

  for (int p : primes) {
    while (fcnt[p] > 0) {
      res.push_back(p);
      for (int j = 2; j <= p; j++) divide(j, fcnt);
    }
  }

  for (int d : res) {
    cout << d;
  }

  cout << '\n';
}
