#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int m, mc, s, sc;
  cin >> m >> s;
  mc = m;
  sc = s;

  int lo = 0, hi = 0;

  if ((9 * m) < s || s < 1) {
    cout << "-1 -1\n";
    return 0;
  }

  while (m > 0) {
    cout << lo << "\n";
    if (s >= 9) {
      lo = lo * 10 + 9;
      s -= 9;
    } else if (s < 9) {
      lo = lo * 10 + s;
      s = 0;
    } else if (s == 0) {
      lo = lo * 10;
    }
    m--;
  }

  m = mc;
  s = sc;

  bool first = true;

  // while (m > 0) {

  // 	if (first) {
  // 		for (int i = 1; i <= 9; i++) {
  // 			if (9 * (m - 1) < (s - i)) continue;
  // 			if (i > s) continue;
  // 			hi = hi * 10 + i;
  // 			s -= i;
  // 			first = false;
  // 			break;
  // 		}
  // 	} else {
  // 		for (int i = 0; i <= 9; i++) {
  // 			if (9 * (m - 1) < (s - i)) continue;
  // 			if (i > s) continue;
  // 			hi = hi * 10 + i;
  // 			s -= i;
  // 			break;
  // 		}
  // 	}
  // 	m--;
  // }

  cout << hi << " " << lo << "\n";
}