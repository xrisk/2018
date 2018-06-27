#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>

typedef long long LL;

using namespace std;

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2; cin >> s1 >> s2;
	int len = s1.size();
	int cnt = 0;

	for (int i = 0; i < len - 1; i++) {
		if (s1[i] == '0' && s2[i] == '0' && s1[i + 1] == '0') {
			cnt++;
			s1[i] = '1'; s2[i] = '1'; s1[i + 1] = '1';
		} 
		if (s1[i] == '0' && s2[i] == '0' && s2[i + 1] == '0') {
			cnt++;
			s1[i] = '1'; s2[i] = '1'; s2[i + 1] = '1';
		}
		if (s1[i] == '0' && s1[i + 1] == '0' && s2[i + 1] == '0') {
			cnt++;
			s1[i] = '1'; s1[i + 1] = '1'; s2[i + 1] = '1';
		}
		if (s1[i + 1] == '0' && s2[i] == '0' && s2[i + 1] == '0') {
			cnt++;
			s1[i + 1] = '1'; s2[i] = '1'; s2[i + 1] = '1';
		}
	}
	cout << cnt << '\n';
}