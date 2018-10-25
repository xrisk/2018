#include <iostream>

using namespace std;

#define LL long long
const int MOD = 1e9 + 7;

LL modpow(LL a, LL pow) {
	LL res = 1;
	while (pow) {
		if (pow % 2 == 1)
			res = (a * res) % MOD;
		pow /= 2;
		a = (a * a) % MOD;
	}
	return res;
}

LL mmi(LL x) {
	return modpow(x, MOD - 2);
}

LL ncr(LL n, LL r) {
	if (r <r > n) return 0;
	LL num = 1;
	LL denom = 1;
	LL x = n;
	LL y = 1;
	cout << n << " C " << r << " => ";
	while (r--) 
	{
		num *= x--;
		denom *= y++;
		num = (num + MOD) % MOD;
		denom = (denom + MOD) % MOD;
	}
	LL ret = (num * mmi(denom)) % MOD;
	cout << ret << '\n';
	return ret;
}

int main()
{

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif
	int T; cin >> T;
	while (T--)
	{
		LL n, k; cin >> n >> k;
		LL sum = 0;
		for (int r = 1; r <= k; r++) {
			LL a = modpow(2, r);

			a = (a * ncr(k - 1, r - 1)) % MOD;
			a = (a * ncr(n - k + 1, r)) % MOD;
			sum = (sum + a) % MOD;
		}
		cout << sum << '\n';
	}
	
}