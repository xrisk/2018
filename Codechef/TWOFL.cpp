#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

typedef long long LL;

using namespace std;

const int NMAX = 105;

int m, n;
int mat[NMAX][NMAX];
int visited[NMAX][NMAX];
set<int> tracker[NMAX][NMAX];

int dfs(int x, int y, int c1, int c2) {
  // cout << "dfs called " << x << " " << y << " " << c1 << " " << c2 << "\n";
  if (x < 0 || x >= n) return 0;
  if (y < 0 || y >= m) return 0;
  if (visited[x][y]) return 0;
  if (!(mat[x][y] == c1 || mat[x][y] == c2)) return 0;
  visited[x][y] = true;
  if (c1 != mat[x][y]) tracker[x][y].insert(c1);
  if (c2 != mat[x][y]) tracker[x][y].insert(c2);
  int r = 0;
  r += dfs(x + 1, y, c1, c2);
  r += dfs(x, y + 1, c1, c2);
  // cout << r << "\n";
  return 1 + r;
}

int begin(int x, int y) {
  int r = -1;
  // if (x != 0) { memset(visited, 0, sizeof visited); r = max(r, dfs(x - 1, y,
  // mat[x][y], mat[x - 1][y])); }
  if (x != n - 1 &&) {
    memset(visited, 0, sizeof visited);
    r = max(r, dfs(x, y, mat[x][y], mat[x + 1][y]));
  }
  // if (y != 0) { memset(visited, 0, sizeof visited); r = max(r, dfs(x, y - 1,
  // mat[x][y], mat[x][y - 1])); }
  if (y != m - 1) {
    if (x != n - 1 && mat[x + 1][y] != mat[x][y + 1]) {
      memset(visited, 0, sizeof visited);
      r = max(r, dfs(x, y, mat[x][y], mat[x][y + 1]));
    }
  }
  return r;
}

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> mat[i][j];
  }

  int soln = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      soln = max(soln, begin(i, j));
    }
  }

  cout << soln << "\n";
}
