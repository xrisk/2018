#include <stdio.h>

int main() {

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int T; scanf("%d", &T);
	while (T--) {
		int N, K; scanf("%d%d", &N, &K);
		double r = (K - 1) / (double) K;
		r *= (N - 1);
		printf("%0.18lf\n", 2 * (1 + r));
	}

}