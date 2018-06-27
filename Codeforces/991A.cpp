#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

typedef long long LL;

using namespace std;

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A, B, C, N; 
	cin >> A >> B >> C >> N;

	if (A > (N - 1) || B > (N - 1) || C > (N - 1) || C > min(A, B)) {
		cout << "-1\n";
		return 0;
	}

	int aub = A + B - C;
	int fail = N - aub;
	if 	(aub < 0 || aub > N || fail == 0 )
			cout << "-1\n";
	else
		cout << fail << '\n';
}