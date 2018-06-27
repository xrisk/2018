#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;


typedef pair<int, int> PII;
struct node {
	int pos, ok, t;
	friend ostream & operator<<(ostream &out, node &n) {
		return out << "node{" << n.pos << ", " << n.ok << ", " << n.t << "}";
	}
};

bool cmp(const PII &l, const PII &r) {
	return l.first < r.first;
}


int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	
	while (T--) {
		int N, Q; cin >> N >> Q;

		vector<int> vec(N + 1);
		vector<PII> sorted(N);

		for (int i = 1; i <= N; i++) {
			cin >> vec[i];
			sorted[i - 1] = {vec[i], i};
		}

	

		sort(sorted.begin(), sorted.end());

		while (Q--) {
			// cout << "---------------\n";
		
			int X; cin >> X;
			// cout << " x -> " << X << "\n"; 
			int pos = lower_bound(sorted.begin(), sorted.end(), make_pair(X, 0) , cmp)->second;
		
			// cout << "pos " << pos << "\n";
			vector<node > path;
			vector<bool> used(N + 1);

			int lo = 1, hi = N;

			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				used[mid] = true;
				if (mid == pos) break;
				if (pos > mid) {
					// we need to go right from here
					// lets see if X is actually greater than the elem here
					path.push_back(node{mid, X > vec[mid], X > vec[mid]});
					lo = mid + 1;
				} 
				if (pos < mid) {
					// we need to go left from here
					// lets see if X is actually less than the elem here
					path.push_back(node{mid, X < vec[mid], X > vec[mid]});
					hi = mid - 1;
				}
			}

			int swp_cnt = 0;
			for (auto& i : path) {
				// cout << i << '\n';
				if (swp_cnt == -1) break;
				if (!i.ok) {
					bool d = false;
					for (auto& j : path) {
						if (!j.ok && j.t == !i.t) { 
							// cout << "swapping here" << i << " with " << j << '\n';
							j.ok = true;
							i.ok = true;
							d = true;
							break;
						}
					}
					if (!d) {
						for (int j = 1; j <= N; j++) {
							if (!used[j] && j != pos) {
								if (i.t ^ (X > vec[j])) {
									// cout << i.t << " " << (X > vec[j]) << " " << vec[j] << "\n";
									used[j] = true;
									// cout << "swapping " << i << " with " << j << '\n';
									d = true;
									break;
								}
							}
						}
					}
					if (!d) {
						swp_cnt = -1;
					} else
						swp_cnt++;
				}
			}
			cout << swp_cnt << '\n';
		}

	

	}
}