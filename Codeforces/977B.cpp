#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> ctr;

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	int N; cin >> N;
	string s; cin >> s;

	for (int i = 0; i < N - 1; i++) {
		string sub; sub += s[i]; sub += s[i + 1];
		ctr[sub]++;
	}

	int max = -1; string max_elem;
	for (auto it : ctr) {
		if (it.second > max) {
			max = it.second;
			max_elem = it.first;
		}
	}
	cout << max_elem << '\n';
}