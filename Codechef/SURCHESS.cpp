// rishav.io

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

typedef long long LL;

using namespace std;

// 0 => black
// 1 => white
bool arr[205][205];
int cum_row_black[205][205];
int cum_row_white[205][205];

int cum_col_black[205][205];
int cum_col_white[205][205];

int dp_white[205][205][205];
int dp_black[205][205][205];

int ans[205];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  fill(ans, ans + 205, -1);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int row, col;
  cin >> row >> col;
  for (int i = 0; i < row; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < col; j++) {
      arr[i][j] = s[j] != '0';
    }
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      // let's trying making this a row that starts w black
      if (j != 0) cum_row_black[i][j] = cum_row_black[i][j - 1];
      if (j % 2 == 0 && arr[i][j] != 0) cum_row_black[i][j]++;
      if (j % 2 == 1 && arr[i][j] != 1) cum_row_black[i][j]++;

      // let's try making this a col with starts w white
      if (j != 0) cum_row_white[i][j] = cum_row_white[i][j - 1];
      if (j % 2 == 0 && arr[i][j] != 1) cum_row_white[i][j]++;
      if (j % 2 == 1 && arr[i][j] != 0) cum_row_white[i][j]++;
    }
  }

  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      // let's trying making this a row that starts w black
      if (j != 0) cum_col_black[i][j] = cum_col_black[i][j - 1];
      if (j % 2 == 0 && arr[j][i] != 0) cum_col_black[i][j]++;
      if (j % 2 == 1 && arr[j][i] != 1) cum_col_black[i][j]++;

      // let's try making this a col with starts w white
      if (j != 0) cum_col_white[i][j] = cum_col_white[i][j - 1];
      if (j % 2 == 0 && arr[j][i] != 1) cum_col_white[i][j]++;
      if (j % 2 == 1 && arr[j][i] != 0) cum_col_white[i][j]++;
    }
  }

  // for (int i = 0; i < row; i++) {
  // 	for (int j = 0; j < col; j++)
  // 		cout << cum_col_black[i][j] << ' ';
  // 	cout << '\n';
  // 	for (int j = 0; j < col; j++)
  // 		cout << cum_col_white[i][j] << ' ';
  // 	cout << "\n-------------\n";
  // }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      for (int size = 1; size <= min(row, col); size++) {
        if ((i + size - 1) >= row || (j + size - 1) >= col) break;
        // cout << i << ' ' << j << ' ' << size << endl;
        if (size == 1) {
          dp_black[i][j][size] = (arr[i][j] != 0);
          dp_white[i][j][size] = (arr[i][j] != 1);

          if (ans[size] == -1 || dp_white[i][j][size] < ans[size])
            ans[size] = dp_white[i][j][size];
          if (ans[size] == -1 || dp_black[i][j][size] < ans[size])
            ans[size] = dp_black[i][j][size];

        } else {
          dp_black[i][j][size] = dp_black[i][j][size - 1];
          dp_white[i][j][size] = dp_white[i][j][size - 1];

          if ((i + size - 1) % 2 == 0) {
            // first cell of col is going to be same color as corner cell
            dp_black[i][j][size] +=
                cum_col_black[j + size - 1][i + size - 1] -
                (i == 0 ? 0 : cum_col_black[j + size - 1][i - 1]);
            dp_white[i][j][size] +=
                cum_col_white[j + size - 1][i + size - 1] -
                (i == 0 ? 0 : cum_col_white[j + size - 1][i - 1]);
          } else {
            // if (i == 0 && j == 0 && size == 2) cout << "here";
            dp_black[i][j][size] +=
                cum_col_white[j + size - 1][i + size - 1] -
                (i == 0 ? 0 : cum_col_white[j + size - 1][i - 1]);
            dp_white[i][j][size] +=
                cum_col_black[j + size - 1][i + size - 1] -
                (i == 0 ? 0 : cum_col_black[j + size - 1][i - 1]);
          }

          if ((j + size - 1) % 2 == 0) {
            // first cell of col is going to be same color as corner cell
            dp_black[i][j][size] +=
                cum_row_black[i + size - 1][j + size - 1] -
                (j == 0 ? 0 : cum_row_black[i + size - 1][j - 1]);
            dp_white[i][j][size] +=
                cum_row_white[i + size - 1][j + size - 1] -
                (j == 0 ? 0 : cum_row_white[i + size - 1][j - 1]);
          } else {
            // if (i == 0 && j == 0 && size == 2) cout << "here";
            dp_black[i][j][size] +=
                cum_row_white[i + size - 1][j + size - 1] -
                (j == 0 ? 0 : cum_row_white[i + size - 1][j - 1]);
            dp_white[i][j][size] +=
                cum_row_black[i + size - 1][j + size - 1] -
                (j == 0 ? 0 : cum_row_black[i + size - 1][j - 1]);
          }

          // if (i == 0 && j == 0 && size == 2) {
          // 	cout << "DEBUG: " << cum_row_white[1][1] << '\n';
          // 	cout << "DEBUG: " << cum_col_white[1][1] << '\n';
          // 	cout << "DEBUG: " << dp_black[i][j][size] << '\n';
          // }

          if (arr[i + size - 1][j + size - 1] == 0)
            dp_white[i][j][size]--;
          else
            dp_black[i][j][size]--;

          if (ans[size] == -1 || dp_white[i][j][size] < ans[size])
            ans[size] = dp_white[i][j][size];
          if (ans[size] == -1 || dp_black[i][j][size] < ans[size])
            ans[size] = dp_black[i][j][size];
        }
      }
    }
  }

  // for (int i = 0; i < row; i++) {
  // 	for (int j = 0; j < col; j++)
  // 		cout << cum_row_white[i][j] << ' ';
  // 	cout << '\n';
  // }

  // cout << "\n-----------\n";

  // for (int i = 0; i < row; i++) {
  // 	for (int j = 0; j < col; j++)
  // 		cout << cum_col_white[j][i] << ' ';
  // 	cout << '\n';
  // }

  // cout << "\n--------------\n";

  int Q;
  cin >> Q;

  // cout << dp_black[0][0][1] << ' ' << dp_black[0][0][2] << '\n';

  // cout << "------" << '\n';

  // for (int i = 0; i < row; i++) {
  // 	for (int j = 0; j < col; j++) {
  // 		cout << dp_white[i][j][2] << ' ';
  // 	}
  // 	cout << '\n';
  // }

  // cout << "\n-----\n";

  while (Q--) {
    int q;
    cin >> q;
    for (int i = min(row, col); i >= 0; i--) {
      if (ans[i] != -1 && ans[i] <= q) {
        cout << i << '\n';
        break;
      }
    }
  }
}