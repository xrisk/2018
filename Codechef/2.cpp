#include <limits.h>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

constexpr int NMAX = 1e5 + 1;

typedef long long LL;

vector<LL> vec(NMAX);
vector<LL> pos(NMAX);
vector<LL> pos2(NMAX);
vector<LL> neg(NMAX);
vector<LL> pos_sub(NMAX);
vector<LL> pos2_sub(NMAX);
vector<LL> neg_sub(NMAX);
vector<LL> soln(NMAX);

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
    cin >> N;

    for (int i = 0; i < N; i++) {
      cin >> vec[i];
    }

    if (N == 1) {
      cout << vec[0] << "\n";
      continue;
    }

    pos[0] = vec[0];
    pos2[0] = vec[0];
    neg[0] = -vec[0];

    pos_sub[0] = vec[0];
    pos2_sub[0] = vec[0];
    neg_sub[0] = -vec[0];

    // for (int i = 1; i < N; i++) {∫
    // 	pos[i] = vec[i] + pos[i - 1];
    // 	if ((vec[i] - vec[i - 1] > 0) && neg[i - 1] != INT_MAX)
    // 		pos[i] = min(pos[i], vec[i] + neg[i - 1]);
    // 	// ------
    // 	if (vec[i - 1] + vec[i] < 0) neg[i] = INT_MAX;
    // 	else neg[i] = -vec[i] + pos[i - 1];

    // }

    for (int i = 1; i < N; i++) {
      // we can put a plus here always

      pos[i] = vec[i] + pos[i - 1];
      pos_sub[i] = min(vec[i], pos_sub[i - 1] + vec[i]);

      if (pos2[i - 1] != LLONG_MAX) {
        pos[i] = min(pos[i], vec[i] + pos2[i - 1]);
        pos_sub[i] = min(pos_sub[i], vec[i] + pos2_sub[i - 1]);
      }

      // lets try putting a neg before this plus
      if ((vec[i] + neg_sub[i - 1]) > 0 && neg_sub[i - 1] != LLONG_MAX) {
        pos2[i] = vec[i] + neg[i - 1];
        pos2_sub[i] = min(vec[i], neg_sub[i - 1] + vec[i]);
      } else {
        pos2[i] = LLONG_MAX;
        pos2_sub[i] = LLONG_MAX;
      }

      // lets try putting a neg here
      // we can only do this if...
      neg[i] = LLONG_MAX;
      neg_sub[i] = LLONG_MAX;
      if (pos_sub[i - 1] > vec[i] && pos_sub[i - 1] != LLONG_MAX) {
        neg[i] = pos[i - 1] - vec[i];
        neg_sub[i] = min(-vec[i], pos_sub[i - 1] - vec[i]);
      }
      if (pos2_sub[i - 1] > vec[i] && pos2_sub[i - 1] != LLONG_MAX) {
        neg[i] = min(neg[i], pos2[i - 1] - vec[i]);
        neg_sub[i] = min(neg_sub[i], min(-vec[i], pos2_sub[i - 1] - vec[i]));
      }
    }

    // for (int i = 0; i < N; i++) {
    // 	cout << i << " --> " << pos[i] << " " << pos2[i] << " "
    // 		 << neg[i] << " ::: ";
    // 	cout << pos_sub[i] << " " <<pos2_sub[i] << "  " << neg_sub[i] << "\n";
    // 	}

    soln[N - 1] = min(pos[N - 1], min(pos2[N - 1], neg[N - 1]));
    if (neg[N - 1] == soln[N - 1]) vec[N - 1] *= -1;

    for (int i = N - 1; i >= 1; i--) {
      // if (flip[i]) vec[i] *= -1;
      if (pos[i - 1] != LLONG_MAX && soln[i] == vec[i] + pos[i - 1]) {
        soln[i - 1] = pos[i - 1];
        // vec[i - 1] = false;
      } else if (pos2[i - 1] != LLONG_MAX && soln[i] == vec[i] + pos2[i - 1]) {
        soln[i - 1] = pos2[i - 1];
        // flip[i - 1] = false;
      } else if (neg[i - 1] != LLONG_MAX && soln[i] == vec[i] + neg[i - 1]) {
        soln[i - 1] = neg[i - 1];
        // flip[i - 1] = true;
        vec[i - 1] *= -1;
      }
    }

    // if (flip[0]) vec[0] *= -1;
    for (int i = 0; i < N; i++) {
      cout << vec[i] << " ";
    }
    cout << "\n";
  }
}
