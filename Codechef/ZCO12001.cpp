#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
#define MP make_pair

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int N;
  cin >> N;
  vector<int> vec(N);

  for (int i = 0; i < N; i++) cin >> vec[i];

  stack<PII> st;

  int cur_depth = 0;
  int best_depth = 0;
  int best_depth_pos = 0;

  int longest = 0;
  int longest_pos = 0;
  for (int i = 0; i < N; i++) {
    if (vec[i] == 1) {
      st.push(MP(1, i));
      cur_depth++;
      if (cur_depth > best_depth) {
        best_depth = cur_depth;
        best_depth_pos = i;
      }
    } else {
      PII p = st.top();
      st.pop();
      if ((i - p.second + 1) > longest) {
        longest = (i - p.second + 1);
        longest_pos = p.second;
      }
      cur_depth--;
    }
  }
  cout << best_depth << ' ' << best_depth_pos + 1 << ' ';
  cout << longest << ' ' << longest_pos + 1 << '\n';
}