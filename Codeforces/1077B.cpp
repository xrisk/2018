// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;

typedef long long LL;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int n; cin >> n;
	vector<int> vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	int k = 0; 
	vector<int> sols;
	for (int i = 1; i < n - 1; i++) {
		if (vec[i] == 0) {
			if (vec[i - 1] == 1 && vec[i + 1] == 1) {
				k++;
				vec[i + 1] = 0;
			}
		}
	}

	cout << k << '\n';

}
