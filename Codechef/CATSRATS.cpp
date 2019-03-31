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

	#define int long long

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int T;

	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;

		vector<int> ai, bi, si;
		vector<int> ci, di, ri;

		for (int i = 0; i < N; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			ai.push_back(x);
			bi.push_back(y);
			si.push_back(z);
			// cout << "x " << x << '\n';
			// cout << "x " << y << '\n';
			// cout << "x " << z << '\n';
		}

		for (int i = 0; i < M; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			ci.push_back(x);
			di.push_back(y);
			ri.push_back(z);
			// cout << " rat \n";
			// cout << "x " << x << '\n';
			// cout << "y " << y << '\n';
			// cout << "z " << z << '\n';
		}

		// cats = N, ai, bi, si
		// rats = M

		// for each rat

		for (int i = 0; i < M; i++) {

			
int answer = INT_MAX;
double answer_time = INT_MAX;


			for (int j = 0; j < N; j++) {

				int rat_start = ci[i], rat_end = di[i];
				int rat_t_start = ri[i], rat_t_end = rat_t_start + abs(rat_end - rat_start);
				int dir = (rat_end >= rat_start) ? 1 : -1;

				
				

				int cat_start = ai[j];
				int cat_end = bi[j];
				int cat_t_start = si[j];
				int cat_t_end = cat_t_start + abs(cat_end - cat_start);
				int catdir = (cat_end >= cat_start) ? 1 : -1;

				// int distance = abs(cat_start - rat_start);

				// cout << dir 
	
				int rel = (dir == catdir) ? 0 : 2;

					// cout << "rel" << rel << '\n';
					// cout << "catdir" << catdir << '\n';
					// cout << "dir" << dir << '\n';
					// cout << "rat: " << rat_start << ' ' << rat_end << ' ' << rat_t_start << ' ' << rat_t_end << '\n';
					// cout << "cat: " << cat_start << ' ' << cat_end << ' ' << cat_t_start << ' ' << cat_t_end << '\n';

				if (rel == 0) {

					if (rat_t_start <= cat_t_start && cat_t_start <= rat_t_end) {
						// cout << "here";
						int tdiff = abs(rat_t_start - cat_t_start);
						// cout << "dir" <<  dir << endl;
						if (rat_start + dir * tdiff == cat_start) {
							if (cat_t_start < answer_time ) {
								answer = j + 1;
								answer_time = cat_t_start;
							}
						}
					} else if (cat_t_start <= rat_t_start && rat_t_start <= cat_t_end) {
						int tdiff = abs(cat_t_start - rat_t_start);
						if (cat_start + catdir * tdiff == rat_start) {
							if (rat_t_start < answer_time) {
								answer = j + 1;
								answer_time = rat_t_start;
							}
						}
					} 
					
				} else if (rel == 2) {

					// lets bring them to equal time

					
					int tdiff = abs(cat_t_start - rat_t_start);

					if (cat_t_start < rat_t_start) {
						cat_start += catdir * tdiff;
						if (cat_t_start + tdiff > cat_t_end) continue;

					} else if (rat_t_start < cat_t_start) {
						rat_start += dir * tdiff;
						if (rat_t_start + tdiff > rat_t_end) continue;
					}

					// cout << "here";
					// cout << cat_t_start

					// double extra_time = abs(cat_t_start - rat_start);

					int distance = abs(cat_start - rat_start);


					double time = distance / 2.0;

					// cout << "time " << time << '\n';

					if (max(cat_t_start, rat_t_start) + time <= cat_t_end && max(cat_t_start, rat_t_start) + time <= rat_t_end) {

						if (cat_start + catdir * time == rat_start + dir * time) {
							// cout << "here";
							if (max(cat_t_start, rat_t_start) + time < answer_time) {
								answer = j + 1;
								answer_time = max(cat_t_start, rat_t_start) + time;
							}
						}
					}
					

					

					
					
					
				}

			}

			if (answer == INT_MAX) {
				cout << "-1\n";
			} else
			cout << answer << '\n';
		}
	}

}
