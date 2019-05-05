// rishav.io

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

typedef long long LL;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    string s1, s2;
    cin >> s1 >> s2;
    bool found = false;

    for (int i = 0; i < 3 && !found; i++) {
      if (s1[i] == 'o' || s2[i] == 'o') {
        int bc = 0;
        for (int j = 0; j < 3; j++) {
          if (j == i) continue;
          if (s1[j] == 'b' || s2[j] == 'b') bc++;
        }

        if (bc == 2) {
          cout << "yes\n";
          found = true;
        }
      }
    }
    if (!found) cout << "no\n";
  }
}