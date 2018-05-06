#include <iostream>
#include <string>
#include <vector>

typedef long long int LL;

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	std::string num;
	std::vector<char> out;

	int ndig; std::cin >> ndig;
	std::cin >> num;

	std::vector<int> counts(10);
	
	for (char c : num) {
		int d = c - '0';
		if (d == 5) counts[5]++;
		else if (d == 7) counts[7]++;
		else {
			while (d % 3 == 0) { counts[3]++; d /= 3; }
			while (d % 2 == 0) { counts[2]++; d /= 2; }
		}
	}

	for (int count : counts) {
		std::cout << count << " ";
	}
	std::cout << '\n';

	std::cout << std::string(counts[7], '7');
	std::cout << std::string(counts[5], '5');
	std::cout << std::string(counts[3], '3');
	std::cout << std::string(counts[3] - counts[2], '2');
	std::cout << '\n';

}