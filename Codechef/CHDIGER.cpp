// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>

using namespace std;

typedef long long LL;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);



	int T; cin >> T;
	while (T--) {
		string N; int d;  
		cin >> N >> d;
		while (true) {
			string t = N;
			// cout << N << '\n';
			t.append(to_string(d));
			bool fl = false;
			for (int i = 0; i < static_cast<int>(t.size()) - 1 ; ++i) {
				if (t[i] > t[i + 1]) {
					fl = true;
					N = t.substr(0, i) + t.substr(i + 1);
					break;
				}
			}
			if (!fl) break;
		}
		cout << N << '\n';
	}

}
