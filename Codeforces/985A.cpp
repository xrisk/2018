#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<int> vec(n / 2);

  vector<int> even;
  vector<int> odd;

  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0)
      even.push_back(i);
    else
      odd.push_back(i);
  }

  for (int i = 0; i < n / 2; i++) {
    cin >> vec[i];
  }

  sort(vec.begin(), vec.end());

  int t1 = 0, t2 = 0;

  for (int i = 0; i < n / 2; i++) {
    // cout << odd[i] << " " << vec[i] << " " << even[i] << "\n";
    t1 += abs(odd[i] - vec[i]);
    t2 += abs(even[i] - vec[i]);
  }

  cout << min(t1, t2) << "\n";
}