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

map<char, vector<int>> freq;
vector<char> idk(595);

void query(int pos) {
  cout << pos + 1 << endl;
  string inp;
  getline(cin, inp);
  cerr << "Read " << inp << endl;
  if (inp[0] == 'N') exit(1);
  freq[inp[0]].push_back(pos);
  idk[pos] = inp[0];
}

void solve(int _t) {
  map<char, vector<int>> freq;
  vector<char> idk(595);
  vector<int> tmp;
  for (int i = 0; i < 5; i++) {
    query(3 * i);
  }
  string out;
  for (auto p : freq) {
    if (p.second.size() == 1) out += p.first;
  }
  char last = out[out.size() - 1];
  tmp.assign(freq[last].begin(), freq[last].end());
  freq.clear();
  for (int x : tmp) {
    query(x + 1);
  }
  for (auto p : freq) {
    if (p.second.size() == 3) out += p.first;
  }
  last = out[out.size() - 1];
  tmp.assign(freq[last].begin(), freq[last].end());
  freq.clear();
  for (int x : tmp) {
    query(x + 1);
  }
  for (auto p : freq) {
    if (p.second.size() == 2) out += p.first;
  }
  last = out[out.size() - 1];
  tmp.assign(freq[last].begin(), freq[last].end());
  freq.clear();
  for (int x : tmp) {
    query(x + 1);
  }
  for (auto p : freq) {
    if (p.second.size() == 1) out += p.first;
  }
  last = out[out.size() - 1];
  tmp.assign(freq[last].begin(), freq[last].end());
  freq.clear();
  for (int x : tmp) {
    query(x + 1);
  }

  vector<bool> foo(5);
  for (char c : out) {
    foo[c - 'A'] = true;
  }

  for (int i = 0; i < 5; i++) {
    if (!foo[i]) out += 'A' + i;
  }

  cout << "Case #" << _t << ": " << out << endl;
  string s;
  cin >> s;
  if (s != "Y") {
    exit(1);
  }
}

int main() {
  // 	ios_base::sync_with_stdio(false);
  // 	cin.tie(0);

  int T, F;
  cin >> T;
  cin >> F;
  cerr << "F => " << F << endl;
  cin.ignore();
  for (int _t = 1; _t <= T; _t++) {
    solve(_t);
    // cout << "here\n";
  }

  // #ifdef __APPLE__
  // 	freopen("input.txt", "r", stdin);
  // #endif
}