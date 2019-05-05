#include <iostream>

using namespace std;

int n;
char arr[105][105];
int store[105][105];

bool get(int i, int j) {
  if (i < 0 || i >= n) return 0;
  if (i < 0 || j >= n) return 0;
  return arr[i][j] == '.';
}

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int K;
  cin >> n >> K;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) arr[i][j] = s[j];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cnt = 0;
      for (int k = 0; k < K; k++) {
        if (get(i + k, j)) cnt++;
      }
      if (cnt == K) {
        for (int k = 0; k < K; k++) store[i + k][j] += 1;
      }
      cnt = 0;
      for (int k = 0; k < K; k++) {
        if (get(i, j + k)) cnt++;
      }
      if (cnt == K) {
        for (int k = 0; k < K; k++) store[i][j + k] += 1;
      }
    }
  }

  int maxval = INT_MIN;
  int maxx = 0, maxy = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (store[i][j] > maxval) {
        maxval = store[i][j];
        maxx = i;
        maxy = j;
      }
    }
  }

  cout << maxx + 1 << " " << maxy + 1 << '\n';
}