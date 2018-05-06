#include <iostream>
#include <vector>

int main() {

	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	int N; std::cin >> N;
	std::vector<int> vec(N);
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
		sum += vec[i];
	}
	long long half = 0;
	for (int i = 0; i < N; i++) {
		half += vec[i];
		if (half * 2 >= sum) {
			std::cout << (i + 1) << "\n";
			break;
		}
	}

}