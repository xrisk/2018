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
	vector<int> l[27];
	vector<int> r[27];
	string a, b;

	cin >> a;
	for (int i = 0; i < n; i++) {
		if (a[i] == '?') l[26].push_back(i);
		else				l[a[i] - 'a'].push_back(i);
	}
	cin >> b;
	for (int i = 0; i < n; i++) {
		if (b[i] == '?') r[26].push_back(i);
		else				r[b[i] - 'a'].push_back(i);
	}

	
	vector<pair<int, int>> soln;
	vector<bool> used(n);
	fill(used.begin(), used.end(), false);

	
	for (int i = 0; i < n; i++) {
		char ch = a[i];
		if (ch != '?') {
			if (r[ch - 'a'].size() != 0) {
				soln.push_back({i, r[ch - 'a'].back()});
				used[r[ch - 'a'].back()] = true;
				r[ch - 'a'].pop_back();
			} else if (r[26].size() != 0) {
				soln.push_back({i, r[26].back()});
				used[r[26].back()] = true;
				r[26].pop_back();
			}
		}
	}

	int ptr = 0;
	for (int i = 0; i < n; i++) {
		if (ptr >= n) break;
		char ch = a[i];
		if (ch == '?') {
			while (ptr < n && used[ptr]) 
				ptr++;
			if (ptr >= n) break;
			soln.push_back({i, ptr});
			used[ptr] = true;
		}
	}

	cout << soln.size() << '\n';
	for (auto &p : soln) {
		cout << p.first + 1 << " " << p.second + 1<< '\n';
	}


		
	
	
}


