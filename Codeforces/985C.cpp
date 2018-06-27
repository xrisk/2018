#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	LL n, k, l; cin >> n >> k >> l;
	vector<LL> vec(n * k);

	for (int i = 0; i < (n * k); i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	LL m = vec[0];
	LL pos = upper_bound(vec.begin(), vec.end(), m + l) - vec.begin();
	if (pos < n) {
		cout << "0\n";
		return 0;
	}

	LL s = 0;
	int cur = 0;
	vector<LL> cnt(n);

	for (int i = 0; i < pos; i++) {
		cerr << "deciging on stave " << i << "\n";
	}


	cout << s << "\n";
	
}