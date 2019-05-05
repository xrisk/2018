#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<int> w(n);

  priority_queue<PII> intro;
  priority_queue<PII> extro;

  for (int i = 0; i < n; i++) {
    cin >> w[i];
    intro.push(make_pair(-w[i], i + 1));
  }

  string pass;
  cin >> pass;

  for (char c : pass) {
    if (c == '0') {
      PII t = intro.top();
      intro.pop();
      cout << t.second << " ";
      PII t2 = make_pair(-t.first, t.second);
      extro.push(t2);
    } else {
      PII t = extro.top();
      extro.pop();
      cout << t.second << " ";
    }
  }

  cout << "\n";
}