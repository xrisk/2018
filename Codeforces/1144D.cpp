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

int main() {

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int n; cin >> n;
	vector<int> vec(n);

	map<int, int> count;
	int max = INT_MIN;
	int maxval = -1;

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		count[vec[i]]++;
		if (count[vec[i]] > max) {
			max = count[vec[i]];
			maxval = vec[i];
		}
	}

	if (max == n) {
		cout << "0\n";
		return 0;
	}
	

	// cout << "maxval" << maxval << endl;
	int first = find(vec.begin(), vec.end(), maxval) - vec.begin();
	// cout << first << endl;

	vector<pair<int, pair<int, int>>> ops;



	for (int i = first - 1; i >= 0; i--) {
		// cout << i << '\n';
		if (i + 1 >= n) break;
		if (vec[i] < vec[i + 1]) {
			// cout << "1 " << i + 1 << ' ' << i + 2 << '\n';
			ops.push_back(make_pair(1, make_pair(i + 1, i + 2)));
		} else {
			// cout << "2 "  << i + 1 << ' ' << i + 2 << '\n';
			ops.push_back(make_pair(2, make_pair(i + 1, i + 2)));

		}
		vec[i] = maxval;
	}

	while (first < n && vec[first] == maxval) first++;

	// cout << "here " << first << '\n';

	for (int i = first; i < n; i++) {
		if (i == 0) continue;
		if (vec[i] == vec[i - 1]) continue;
		if (vec[i] < vec[i - 1]) {
			// cout << "2 " << i << " " << i - 1 << '\n';
			ops.push_back(make_pair(1, make_pair(i + 1, i)));
		} else {
			// cout << "1 " << i << " " << i - 1 << '\n'
			ops.push_back(make_pair(2, make_pair(i + 1, i)));

		}
		vec[i] = maxval;
	}

	cout << ops.size() << '\n';
	for (auto c : ops) {
		cout << c.first << ' ' << c.second.first << ' ' << c.second.second << '\n';
	}
 

	
}