// rishav.io

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <climits>
#include <utility>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int T; cin >> T;
	while (T--) {
		vector<int> count(32);
		int N; cin >> N;
		vector<int> vec(N);
		for (int i = 0; i < N; i++) {
			cin >> vec[i];
			for (int j = 0; j < 32; j++) {
				if (vec[i] & (1 << j)) count[j]++;
			}
		}
		int sol = 0;
		for (int i = 0; i < 32; i++) {
			if (2 * count[i] >= N) {
				sol |= (1 << i);
			}
		}
		LL r = 0;
		for (auto x : vec) 
			r += (x ^ sol);
		cout << r << '\n';
	}


	
}