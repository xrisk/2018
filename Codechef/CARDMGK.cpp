#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    long long arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];

    int mini = arr[0];
    int id = 0;

    for (int i = 0; i < n; i++) {
      if (arr[i] < mini) {
        mini = arr[i];
        id = i;
      }
    }

    int f = 0;

    // cout<<id<<"  "<<mini<<endl;

    for (int i = id + 1; i != id; i = (i + 1) % n) {
      if (i == 0) {
        if (arr[n - 1] > arr[i]) {  // cout<<"here"<<i;
          f = 1;
          break;
        }

      }

      else {
        if (arr[i - 1] > arr[i]) {
          // cout<<i<<" "<<i-1<<" ";

          f = 1;
          break;
        }
      }
    }

    if (f == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}