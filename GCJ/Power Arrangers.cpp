// rishav.io

#include <algorithm>
#include <cassert>
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

char query(int pos) {
  cout << pos + 1 << endl;
  string inp;
  getline(cin, inp);
  // cerr << "Read " << inp << endl;
  if (inp[0] == 'N') exit(1);
  char c = inp[0];
  if (c != 'A' && c != 'B' && c != 'C' && c != 'D' && c != 'E')
    return query(pos);
  freq[inp[0]].push_back(pos);
  idk[pos] = inp[0];
  return inp[0];
}

void solve(int _t) {
  map<char, vector<int>> freq;
  vector<char> idk(595);

  freq.clear();
  idk.clear();
  idk.resize(595);

  vector<int> tmp;
  for (int i = 0; i < 119; i++) {
    query(5 * i);
  }
  // cerr << endl;
  string out;
  for (auto p : freq) {
    // cerr << p.second.size() << endl;
    if (p.second.size() == 23) out += p.first;
  }
  char last = out[out.size() - 1];
  tmp.assign(freq[last].begin(), freq[last].end());
  freq.clear();
  for (int x : tmp) {
    query(x + 1);
  }
  for (auto p : freq) {
    if (p.second.size() == 5) out += p.first;
  }
  last = out[out.size() - 1];
  tmp.assign(freq[last].begin(), freq[last].end());
  freq.clear();
  for (int x : tmp) {
    query(x + 1);
  }
  for (auto p : freq) {
    // cerr << "foo " << p.second.size() << endl;
    if (p.second.size() == 1) out += p.first;
  }

  // cerr << out << endl;

  // cout << "last " << last << endl;
  // at this point out has 3 chars
  // cerr << "out => " << out << endl;
  last = out[out.size() - 1];
  tmp.assign(freq[last].begin(), freq[last].end());

  // tmp has one element
  // cerr << "tmp size" << tmp.size() << endl;
  assert(tmp.size() == 1);
  char f = query(tmp[0] + 1);

  // append the char not in out but which is not f
  vector<bool> foo(5);
  for (char c : out) {
    foo[c - 'A'] = true;
  }

  // cerr << out << endl;

  // cerr << " f => " << f << endl;
  for (int i = 0; i < 5; i++) {
    if (foo[i] == false && ('A' + i != f)) {
      out += ('A' + i);
      break;
    }
  }

  // finally append f
  // cerr << "out WTF => " << out << endl;
  out += f;

  // cerr << out << endl;

  cout << out << endl;
  string s;
  getline(cin, s);
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
  // cerr << "F => " << F << endl;
  cin.ignore();
  for (int _t = 1; _t <= T; _t++) {
    solve(_t);
    // cout << "here\n";
  }

  // #ifdef __APPLE__
  // 	freopen("input.txt", "r", stdin);
  // #endif
}