// rishav.io

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

bool p(vector<LL> &A, vector<LL> &B) {
  int N = A.size();
  for (int i = 0; i < N - 2; i++) {
    if (A[i] > B[i]) return false;
    if (A[i] == B[i]) continue;
    LL diff = B[i] - A[i];
    A[i] += diff;
    A[i + 1] += (2 * diff);
    A[i + 2] += (3 * diff);
  }
  if (A[N - 1] != B[N - 1]) return false;
  if (A[N - 2] != B[N - 2]) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<LL> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    if (p(A, B))
      cout << "TAK\n";
    else
      cout << "NIE\n";
  }
}
