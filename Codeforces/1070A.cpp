// rishav.io

#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

// queue<array<int, 3>> q;

class tup {
 public:
  int x, y;
  string s;
  tup(int x, int y, string s) : x(x), y(y), s(s) {}
  int first() { return x; }
  int second() { return y; }
};

bool vis[505][5005];

queue<tup> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int d, s;
  cin >> d >> s;

  q.push(tup(0, 0, ""));
  vis[0][0] = true;

  while (!q.empty()) {
    tup p = q.front();
    q.pop();
    if (p.x != 0 && p.y != 0 && vis[p.x][p.y]) continue;
    vis[p.x][p.y] = true;
    if (p.y > s) continue;
    if (p.x == 0 && p.y == s) {
      cout << p.x << ' ' << p.y << '\n';
      cout << p.s << '\n';
      return 0;
    }
    for (int i = 0; i <= 9; i++) {
      int next_x = (p.x * 10 + i) % d;
      int next_y = p.y + i;
      q.push(tup(next_x, next_y, p.s + to_string(i)));
    }
  }

  cout << "-1\n";
}
