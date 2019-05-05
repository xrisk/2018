#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 2005;

typedef long long LL;
typedef pair<int, int> PII;

int mat[NMAX][NMAX];
int dp1[NMAX][NMAX];

vector<pair<int, int> > dp2[NMAX][NMAX];
int dp22[NMAX][NMAX];

int calc1(int x, int y) {
  int r = -1;
  if (y != 0 && mat[x][y] == mat[x][y - 1]) r = max(r, dp1[x][y - 1] + 1);
  if (x != 0 && mat[x][y] == mat[x - 1][y]) r = max(r, dp1[x - 1][y] + 1);
  dp1[x][y] = max(1, r);
  return dp1[x][y];
}

int calc2(int x, int y) {
  dp22[x][y] = -1;
  if (y != 0 && mat[x][y] == mat[x][y - 1]) {
    for (PII p : dp2[x][y - 1]) {
      dp2[x][y].push_back(make_pair(p.first + 1, p.second));
      dp22[x][y] = max(dp22[x][y], p.first + 1);
    }
  }
  if (y != 0 && mat[x][y] != mat[x][y - 1]) {
    dp2[x][y].push_back(make_pair(dp1[x][y - 1] + 1, mat[x][y - 1]));
    dp22[x][y] = max(dp22[x][y], dp1[x][y - 1] + 1);

    for (PII p : dp2[x][y - 1]) {
      if (p.second == mat[x][y]) {
        dp2[x][y].push_back(make_pair(p.first + 1, mat[x][y - 1]));
        dp22[x][y] = max(dp22[x][y], p.first + 1);
      }
    }
  }
  if (x != 0 && mat[x][y] == mat[x - 1][y]) {
    for (PII p : dp2[x - 1][y]) {
      dp2[x][y].push_back(make_pair(p.first + 1, p.second));
      dp22[x][y] = max(dp22[x][y], p.first + 1);
    }
  }
  if (x != 0 && mat[x][y] != mat[x - 1][y]) {
    dp2[x][y].push_back(make_pair(dp1[x - 1][y] + 1, mat[x][y - 1]));
    dp22[x][y] = max(dp22[x][y], dp1[x - 1][y] + 1);

    for (PII p : dp2[x - 1][y]) {
      if (p.second == mat[x][y]) {
        dp2[x][y].push_back(make_pair(p.first + 1, mat[x - 1][y]));
        dp22[x][y] = max(dp22[x][y], p.first + 1);
      }
    }
  }
  return dp22[x][y];
}

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> mat[i][j];
  }

  int soln = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      soln = max(soln, calc1(i, j));
      soln = max(soln, calc2(i, j));
      cout << "(" << dp1[i][j] << ", " << dp22[i][j] << ") ";
    }
    cout << "\n";
  }
  cout << soln << "\n";
}