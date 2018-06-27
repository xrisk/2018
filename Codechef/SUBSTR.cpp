#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int freq[27][7005];


int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;


	while (T--) {
		
		string s; cin >> s;
		int K; cin >> K;
		for (int i = 0; i < (int)s.size(); i++) {
			for (int j = 0; j < 26; j++) {
				if (i == 0) freq[j][i] = 0;
				else freq[j][i] = freq[j][i - 1];
				if (j == (s[i] - 'a')) freq[j][i]++;
			}
		}

		int sol = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			for (int j = i; j < (int)s.size(); j++) {
				int dis = 0;; int last_f = -1;

				int fl  = true; 
				for (int k = 0; k < 26 && fl; k++) {
					int freq_h; 
					if (i == 0) freq_h = freq[k][j];
					else freq_h = freq[k][j] - freq[k][i - 1];
					// cout << i << " " << j << " " << k << " " << freq_h << "\n";
					if (freq_h != 0) {
						dis++;
						if (last_f == -1) last_f = freq_h;
						else if (last_f != freq_h) { fl = false; break; }
					}
				}
				// cout << cnt ;
				// cout << i << " " << j << " " << dis << " " << cnt.size() << "\n";
				if (dis >= K && fl) 
					sol++;
			}
		}

		cout << sol << "\n";

	}
}