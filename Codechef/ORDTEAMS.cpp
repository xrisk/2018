#include <iostream>
#include <vector>
#include <algorithm>

struct triple {
	int a, b, c;
	friend bool operator<(const triple &x, const triple &y) {
		return x.a < y.a || x.b < y.b || x.c < y.c;
	}
	friend bool operator==(triple &x, triple &y) {
		return x.a == y.a && x.b == y.b && x.c == y.c;
	}
};

void solve() {
	std::vector<triple> vec;
	for (int i = 0; i < 3; i++) {
		int a, b, c; std::cin >> a >> b >> c;
		vec.push_back(triple{a, b, c});
	}
	std::sort(vec.begin(), vec.end());
	for (int i = 0; i < 3; i++) {
		std::cout << vec[i].a << " " << vec[i].b << " " << vec[i].c << "\n";
	}
	if (vec[0] == vec[1] || vec[1] == vec[2]) std::cout << "no\n";
	else std::cout << "yes\n";
}

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	int T; std::cin >> T;

	while (T--) {
		solve();
	}
}