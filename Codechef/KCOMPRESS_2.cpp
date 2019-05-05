#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

constexpr int NMAX = 1e5 + 5;

vector<int> t(2 * NMAX);

int N;

vector<pair<int, int> > vec;
vector<pair<int, int> > vec2;

void build() {
  for (int i = N - 1; i > 0; --i) t[i] = max(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, int value) {
  for (t[p += N] = value; p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
}

int query(int l, int r) {
  int res = INT_MIN;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max(res, t[l++]);
    if (r & 1) res = max(res, t[--r]);
  }
  return res;
}

bool check2(int K, int target) {
  int lastpos = -1, lastval = -1, lastset = -1;

  fill(t.begin(), t.end(), 0);
  for (int i = 0; i < N; i++) {
    // cout << vec2[i].first << ' ' << vec2[i].second << '\n';

    int sec = vec2[i].second * -1;
    if (vec2[i].first == 1) {
      modify(sec, 1);
      lastset = 1;
    } else {
      // int ret = query ( max(0, vec2[i].second - K) ,
      // 			  min(N , vec2[i].second + K + 1));
      // cout << vec2[i].second << ' ' << ret << '\n';
      if (i == 0) {
        lastset = 1;
        modify(sec, 1);
      } else {
        if (lastval == vec2[i].first) {
          int ret = query(max(0, sec - K), min(N, sec + K + 1));

          if (abs(sec - lastpos) <= K) {
            if (lastset == ret)
              modify(sec, lastset);
            else {
              modify(sec, ret + 1);
              lastset = ret + 1;
            }
            // lastset = max(lastset, ret + 1)
          } else {
            lastset = ret + 1;
            modify(sec, ret + 1);
          }

        } else {
          int ret = query(max(0, sec - K), min(N, sec + K + 1));
          lastset = ret + 1;
          modify(sec, ret + 1);
        }
      }
    }
    lastpos = sec;
    lastval = vec2[i].first;
  }

  LL s = 0;

  // cout << K << ": ";
  if (K == 10) cout << "rev: " for (int i = N; i < 2 * N; i++) {
      cout << t[i] << ' ';
      s += t[i];
    }

  cout << " => " << s << '\n';
  return s <= target;
}

bool check(int K, int target) {
  int lastpos = -1, lastval = -1, lastset = -1;

  fill(t.begin(), t.end(), 0);
  for (int i = 0; i < N; i++) {
    if (vec[i].first == 1) {
      modify(vec[i].second, 1);
      lastset = 1;
    } else {
      // int ret = query ( max(0, vec[i].second - K) ,
      // 			  min(N , vec[i].second + K + 1));
      // cout << vec[i].second << ' ' << ret << '\n';
      if (i == 0) {
        lastset = 1;
        modify(vec[i].second, 1);
      } else {
        if (lastval == vec[i].first) {
          int ret =
              query(max(0, vec[i].second - K), min(N, vec[i].second + K + 1));

          if (abs(vec[i].second - lastpos) <= K) {
            if (lastset == ret)
              modify(vec[i].second, lastset);
            else {
              modify(vec[i].second, ret + 1);
              lastset = ret + 1;
            }
            // lastset = max(lastset, ret + 1)
          } else {
            lastset = ret + 1;
            modify(vec[i].second, ret + 1);
          }

        } else {
          int ret =
              query(max(0, vec[i].second - K), min(N, vec[i].second + K + 1));
          lastset = ret + 1;
          modify(vec[i].second, ret + 1);
        }
      }
    }
    lastpos = vec[i].second;
    lastval = vec[i].first;
  }

  LL s = 0;

  // cout << K << ": ";
  for (int i = N; i < 2 * N; i++) {
    // cout << t[i] << ' ';
    s += t[i];
  }

  // cout << " => " << s << '\n';
  return s <= target;
}

main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    int S;
    cin >> N >> S;

    vec.resize(N);
    vec2.resize(N);

    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      vec[i] = make_pair(x, i);
      vec2[i] = make_pair(x, -i);
    }

    sort(vec.begin(), vec.end());
    sort(vec2.begin(), vec2.end());

    int lo = 0;
    int hi = N;

    // check(10, 100);
    // check2(10, 100);

    if (check(hi, S) || check2(hi, S)) {
      cout << hi + 1 << '\n';
    } else {
      while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        cerr << lo << ' ' << mid << ' ' << hi << ' ' << check(mid, S) << ' '
             << check2(mid, S) << '\n';
        if (check(mid, S) || check2(mid, S)) {
          lo = mid + 1;
        } else {
          hi = mid;
        }
      }

      cout << lo << '\n';
    }
  }
}