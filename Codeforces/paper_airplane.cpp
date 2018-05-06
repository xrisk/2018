#include <iostream>
#include <math.h>

using namespace std;
#define LL long long

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	LL k, n, s, p; cin >> k >> n >> s >> p;
	double sheets_per_person = ceil( n / (double) s);

	LL tot = sheets_per_person * k;
	LL pack = ceil ( tot / (double ) p);

	cout << pack << '\n';
}