#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	LL N, K;
	cin >> N >> K;
	vector<LL> vec(N);

	for (int i = 0 ; i < N; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());
	LL sol = 0;

	for (int i = 0; i < N; i++) {
		LL n = vec[i];
		LL lower = upper_bound(vec.begin(), vec.end(), n - K) - vec.begin();
		LL upper = vec.end() - lower_bound(vec.begin(), vec.end(), n + K);
		// cout << i << ' ' << lower << ' ' << upper << '\n'; 
		sol += lower + upper;
	}

	cout << sol / 2 << '\n';

}