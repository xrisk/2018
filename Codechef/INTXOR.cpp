// rishav.io

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> vec(N + 5);
    vector<int> soln(N + 1);

    int v = 0;
    int pre = -1;
    int one = -1;
    int two = -1;
    int last = -1;

    for (int i = 0; i < N / 2; i++) {
      int t1, t2;
      cout << "1 " << v % N + 1 << ' ' << (v + 1) % N + 1 << ' '
           << (v + 2) % N + 1 << endl;
      cin >> t1;
      cout << "1 " << v % N + 1 << ' ' << (v + 1) % N + 1 << ' '
           << (v + 3) % N + 1 << endl;
      cin >> t2;

      if (i == 0) {
        one = t1;
        two = t2;
      } else {
        soln[(v + 2) % N + 1] = t1 ^ pre;
        soln[(v + 3) % N + 1] = t2 ^ pre;
        // cout << "setting " <<
        // 		(v + 2) % N + 1 <<
        // 		(v + 3) % N + 1 << endl;
      }
      v += 2;
      pre = t1 ^ t2;
    }

    if (N % 2 == 1) {
      cout << "1 " << v % N + 1 << ' ' << (v + 1) % N + 1 << ' '
           << (v + 2) % N + 1 << endl;
      cin >> last;
      soln[2] = last ^ pre;
    }
    soln[3] = one ^ soln[1] ^ soln[2];
    soln[4] = two ^ soln[1] ^ soln[2];

    cout << "2 ";
    for (int i = 1; i <= N; i++) {
      cout << soln[i] << ' ';
    }
    cout << endl;
    int ex;
    cin >> ex;
    if (ex == -1) exit(1);
  }
}
