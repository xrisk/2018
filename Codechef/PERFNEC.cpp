#include <iostream>
#include <limits.h>
#include <unordered_map>
#include <utility>
#include <map>

using namespace std;
typedef pair<int, int> PII;

int S, G, Q, R, D;

int ok(int o) {
	switch(o) {
		case 0: return S;
		case 1: return G;
		case 2: return Q;
		case 3: return R;
		case 4: return D;
		default: return -1;
	}
}

map<PII, int>  look;

int calc(int X, int Y) {
	if (X == 0 && Y == 0)
		return 0;
	if (X == 0 && Y != 0)
		return -1;
	if (X == 1) {
		if (Y == -2) return S;
		if (Y == -1) return G;
		if (Y == 0) return Q;
		if (Y == 1) return R;
		if (Y == 2) return D;
		return -1;
	}

	auto f = look.find(make_pair(X, Y));
	if (f != look.end())
		return f->second;

	long long v[5];
	
	v[0] = calc(X - 1, Y + 2);//-2
	v[1] = calc(X - 1, Y + 1);
	v[2] = calc(X - 1, Y);
	v[3] = calc(X - 1, Y - 1);
	v[4] = calc(X - 1, Y - 2);

	long long mincost = -1;

	for (int i = 0; i < 5; i++) {
		if (v[i] != -1) {
			if (mincost == -1)
				mincost = v[i] + ok(i);
			else
				mincost = min(mincost, v[i] + ok(i));
		}
	}

	look[make_pair(X, Y)] = mincost;
	return mincost;

}

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	
	cin >> S >> G >> Q >> R >> D;

	int q; cin >> q;

	while(q--) {
		int X, Y; cin >> X >> Y;
		cout << calc(X, Y) << '\n';
	}
}