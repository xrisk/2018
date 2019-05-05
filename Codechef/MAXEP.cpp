// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

void comb(int lo, int hi) {
  // cout << "combing " << lo << ' ' << hi << endl;
  for (int i = lo; i <= hi; i++) {
    cout << "1 " << i << endl;
    int ret;
    cin >> ret;
    if (ret == 1) {
      cout << "3 " << i << endl;
      exit(0);
    } else if (ret == 0) {
      continue;
    } else if (ret == -1) {
      exit(1);
    }
  }
}

int main() {
  int N, c;
  cin >> N >> c;
  int blk = sqrt(N);

  for (int i = blk;; i += blk) {
    i = min(N, i);
    cout << "1 " << i << endl;
    int ret;
    cin >> ret;
    // cout << "read " << ret << endl;
    if (ret == 0)
      continue;
    else if (ret == 1) {
      cout << "2" << endl;
      comb(max(1, i - blk), i);
    } else if (ret == -1)
      exit(1);
  }
}
