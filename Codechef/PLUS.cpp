#include <limits.h>
#include <iostream>

using namespace std;

const int NMAX = 1005;

int a1[NMAX][NMAX];
int a2[NMAX][NMAX];
int a3[NMAX][NMAX];
int a4[NMAX][NMAX];
int mat[NMAX][NMAX];

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int N;
    int M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) cin >> mat[i][j];
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (j == 0)
          a1[i][j] = mat[i][j];
        else
          a1[i][j] = max(mat[i][j], a1[i][j - 1] + mat[i][j]);
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = M - 1; j >= 0; j--) {
        if (j == M - 1)
          a2[i][j] = mat[i][j];
        else
          a2[i][j] = max(mat[i][j], a2[i][j + 1] + mat[i][j]);
      }
    }

    for (int j = 0; j < M; j++) {
      for (int i = 0; i < N; i++) {
        if (i == 0)
          a3[i][j] = mat[i][j];
        else
          a3[i][j] = max(mat[i][j], a3[i - 1][j] + mat[i][j]);
      }
    }

    for (int j = 0; j < M; j++) {
      for (int i = N - 1; i >= 0; i--) {
        if (i == N - 1)
          a4[i][j] = mat[i][j];
        else
          a4[i][j] = max(mat[i][j], a4[i + 1][j] + mat[i][j]);
      }
    }

    int sol = INT_MIN;
    for (int i = 1; i < N - 1; i++) {
      for (int j = 1; j < M - 1; j++) {
        sol = max(sol, mat[i][j] + a1[i][j - 1] + a2[i][j + 1] + a3[i - 1][j] +
                           a4[i + 1][j]);

        // cout << i << " " << j << " " << a1[i][j - 1] << " " << a2[i][j + 1]
        // << " " << a3[i - 1][j] << " " << a4[i + 1][j] << "\n";
      }
    }
    cout << sol << "\n";
  }
}