#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

vector<LL> vec(14);

LL shift(int pos) {
	LL stones = vec[pos];
	LL ok = stones / 14;
	LL rem = stones % 14;

	LL score = 0;
	vector<LL> newscores(14);
	for (int i = 0; i < 14; i++) {
		if (i == pos) { newscores[i] = ok; }
		else { newscores[i] = vec[i] + ok ;}
	}
	for (int i = 1; i <= rem; i++) {
		newscores[(pos + i) % 14] += 1;
	}
	for ( LL x : newscores) {
	
		if (x % 2 == 0) score += x;
	}
	
	return score;
}

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	for (int i = 0; i < 14; i++)
		cin >> vec[i];

	LL max_score = 0;
	for (int i = 0; i < 14; i++) {
		// cout << i << ' ' << shift(i) << '\n';
		max_score = max(max_score, shift(i));
	}
	cout << max_score << '\n';
}