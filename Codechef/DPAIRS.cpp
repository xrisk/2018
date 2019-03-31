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

	int N, M; cin >> N >> M;
	vector<int> A, B;
	A.resize(N); B.resize(M);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < M; i++)
		cin >> B[i];

	int max = max_element(A.begin(), A.end()) - A.begin();
	int mn = min_element(B.begin(), B.end()) - B.begin();

	for (int i = 0; i < M; i++) {
		cout << max << ' ' << i << '\n';
	}

	for (int i = 0; i < N; i++) {
		if (i == max) continue;
		cout << i << ' ' << mn << '\n';
	}
	

}
