// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;
constexpr int NMAX = 205;

bool p(int x) {
	if (x == 2) return true;
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0) return false;
	return true;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	vector<int> plist;
	vector<int> semi;
	
	for (int i = 2; i <= NMAX; i++) {
		if (p(i)) plist.push_back(i);
	}

	for (int i = 0; i < (int)plist.size(); i++) {
		for (int j = i + 1; j < (int)plist.size(); j++)
			semi.push_back(plist[i] * plist[j]);
	}

	sort(semi.begin(), semi.end());

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		bool f = true;
		for (int c : semi) {
			if (c >= N) continue;
			if (binary_search(semi.begin(), semi.end(), N - c)) {
				cout << "YES\n";
				f = false;
				break;
			}
		}
		if (f) cout << "NO\n";
	}
	

}
