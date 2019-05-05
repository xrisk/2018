#include <iostream>
#include <queue>
#include <utility>

typedef long long LL;

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  LL n;
  std::cin >> n;
  std::vector<long long> out(n);

  std::priority_queue<std::pair<LL, LL>, std::vector<std::pair<LL, LL> >,
                      std::greater<std::pair<LL, LL> > >
      pq;

  for (LL i = 0; i < n; i++) {
    LL x;
    std::cin >> x;
    pq.push(std::make_pair(x, i));
  }

  LL state = 1;  // 1 = looking for new pair, 2 = looking for match
  LL val = -1;
  LL pos = -1;

  while (!pq.empty()) {
    std::pair<LL, LL> p = pq.top();
    pq.pop();
    if (state == 1) {
      // std::cout << "setting pos = " << p.second << '\n';
      val = p.first;
      state = 2;
      pos = p.second;
    } else {
      if (p.first == val) {  // match found
        // std::cout << "match found";
        pq.push(std::make_pair(2 * val, p.second));
        out[p.second] = 2 * val;
        out[pos] = -1;
        state = 1;
      } else {
        // this number is not a match, which means that `val` has no pair
        // std::cout << "hi " << val << " " << pos << "\n";
        out[pos] = val;
        val = p.first;
        pos = p.second;
      }
    }
  }

  if (state == 2) {
    out[pos] = val;
  }

  std::vector<LL> solution;

  for (int i = 0; i < n; i++) {
    if (out[i] != -1) solution.push_back(out[i]);
  }

  std::cout << solution.size() << "\n";
  for (LL n : solution) std::cout << n << " ";
  std::cout << "\n";
}