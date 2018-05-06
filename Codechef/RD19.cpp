#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <limits.h>
#include <math.h>

using namespace std;

map<int, int> cnt;

void factor(int x) {
	for (int i = 2; i <= (int)sqrt(x); i++) {
		if (x % i == 0) {
			cnt[i]++;
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) cnt[x]++;
}


int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	int T; cin >> T;

	while (T--) {

		cnt.clear();
		int N; cin >> N;
		vector<int> vec(N);

		for (int i = 0; i < N; i++)
			cin >> vec[i];

		bool one = false;

		for (int v : vec) {
			if (v == 1) one = true;
			factor(v);
		}

		if (one == true) {
			cout << "0\n";
			return 0;
		}

		int min = INT_MAX;
		for (auto key : cnt) {
			cout << key.first << ' ' << key.second << " test " << '\n';
			if (key.second < min) min = key.second;
		}

		cout << "min " << min << "\n";

		if (min == N) {
			cout << "-1\n";
			return 0;
		}

		cout << min - 1 << "\n";
	}
}