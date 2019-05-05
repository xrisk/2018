#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > vec;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;
    vec.resize(N);
    for (int i = 0; i < N; i++) {
      vec[i].clear();
      vec[i].resize(N);
      for (int j = 0; j < N; j++) cin >> vec[i][j];
    }

    int sol = -1;
    for (int i = 0; i < N; i++) {
      int startx = 0;
      int starty = i;
      int tmp1 = 0;
      int tmp2 = 0;
      while (startx < N && starty < N) {
        tmp1 += vec[startx][starty];
        tmp2 += vec[starty][startx];
        startx += 1;
        starty += 1;
      }
      sol = max(sol, max(tmp1, tmp2));
    }
    cout << sol << "\n";
  }
}
