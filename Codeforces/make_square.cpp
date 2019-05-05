#include <cmath>
#include <iostream>

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  std::string s;
  std::cin >> s;
  int len = s.size();
  int answer = INT_MAX;

  for (int i = 0; i < pow(2, len); i++) {
    int idx = 0;
    int binary = i;
    int out_num = 0;
    int del_count = len;
    while (binary) {
      if (binary % 2 == 1) {
        int dig = s[idx] - '0';
        if (out_num == 0 && dig == 0) break;
        out_num = out_num * 10 + dig;
        del_count--;
      }
      idx++;
      binary /= 2;
    }
    // std::cout << out_num << " " << del_count << "\n";
    int root = sqrt(out_num);
    if (out_num != 0 && root * root == out_num) {
      if (del_count < answer && out_num != 0) {
        // std::cout << "found new answer " << out_num << '\n';
        answer = del_count;
      }
    }
  }

  if (answer == INT_MAX)
    std::cout << "-1\n";
  else
    std::cout << answer << '\n';
}