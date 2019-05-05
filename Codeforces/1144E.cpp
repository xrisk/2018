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

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int k;
  cin >> k;
  string s, t;
  cin >> s;
  cin >> t;

  vector<int> a, b;
  for (char c : s) {
    // cout << c << endl;
    a.push_back(c - 'a');
  }
  for (char c : t) b.push_back(c - 'a');
  vector<int> res;

  int carry = 0;

  for (int i = k - 1; i >= 0; i--) {
    // cout << a[i] << ' ' << b[i] << endl;
    int tmp = a[i] + b[i] + carry;
    carry = tmp / 26;
    int rem = tmp % 26;
    res.push_back(rem);
  }
  if (carry != 0) res.push_back(carry);
  reverse(res.begin(), res.end());

  int kek = 0;

  vector<int> ans;
  for (int i = 0; i < res.size(); i++) {
    kek = kek * 26 + res[i];
    if (kek < 2) {
      ans.push_back(0);
    } else {
      ans.push_back(kek / 2);
      kek %= 2;
    }
    // if (ans.size() == k) break;
  }

  for (int i = ans.size() - k; i < ans.size(); i++) {
    cout << (char)(ans[i] + 'a');
  }

  cout << endl;
}