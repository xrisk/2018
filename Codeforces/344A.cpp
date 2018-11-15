// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int n; cin >> n;

	string first; cin >> first;


	string last_type = first;
	int cnt = 1;



	for (int i = 1; i < n; i++) {
		string s; cin >> s;
		if (s != last_type) cnt++;
		last_type = s;
	}

	cout << cnt << '\n';

}
