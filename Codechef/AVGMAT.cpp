// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
#include <set>
#include <array>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;


constexpr int NMAX = 305;

bool mat[NMAX][NMAX];

vector<int> main_diagonal[2000];
vector<int> cross_diagonal[2000];

int cross_idx[NMAX][NMAX];
int main_idx[NMAX][NMAX];

array<int, 1000> D;

int cons(int val, int low, int high) {
	if (val < low) return low;
	if (val > high) return high;
	return val;
}

ostream& operator<< (ostream &os, pair<int, int> p) {
	return os << "(" << p.first << ", " << p.second << ")";
}

int N, M;

bool v(int x, int y) {

	if (x < 0 || x >= N) return false;
	if (y < 0 || y >= M) return false;
	return true;
}

void init() {
	fill(D.begin(), D.end(), 0);
	for (int i = 0; i < 2000; i++) {
			main_diagonal[i].clear();
			cross_diagonal[i].clear();
	}

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int T; cin >> T;

	while (T--) {

		init();
	
		cin >> N >> M;
		vector<pair<int, int> > ones;		

		for (int i = 0; i < N; i++) {
			string s; cin >> s;
			for (int j = 0; j < M; j++) {
				mat[i][j] = s[j] == '1';
				if (mat[i][j]) ones.push_back(make_pair(i, j));
				cross_idx[i][j] = cross_diagonal[i + j].size();
				main_idx[i][j] = main_diagonal[i - j + 1000].size();
				if (cross_diagonal[i + j].size() == 0) {
					cross_diagonal[i + j].push_back(mat[i][j]);
				} else {
					cross_diagonal[i + j].push_back(cross_diagonal[i + j].back() + mat[i][j]);
				}
				if (main_diagonal[i - j + 1000].size() == 0) {
					main_diagonal[i - j + 1000].push_back(mat[i][j]);
				} else {
					main_diagonal[i - j + 1000].push_back(main_diagonal[i - j + 1000].back() + mat[i][j]);
				}
			}
		}

	
		for (auto& p : ones) {
			int cx = p.first, cy = p.second;


			for (int d = 1; d <= N + M - 2; d++) {
			// for (int d = 1; d <= 1; d++) {

				int cnt = 0;

				PII top = {cx - d, cy};
				PII left = {cx, cy - d};
				PII bottom = {cx + d, cy};
				PII right = {cx, cy + d};


				
				int e1 = top.first - top.second + 1000;


		
				int sz1 = main_diagonal[e1].size();
				// cout << sz1 << '\n';

				if (sz1 > 0) {
					int high = sz1 - 1, low = 0;
					if (v(right.first, right.second)) high = main_idx[right.first][right.second];
					if (v(top.first, top.second)) low = main_idx[top.first][top.second];
					int val = main_diagonal[e1][high];
					if (low > 0) val -= main_diagonal[e1][low - 1];
					cnt += val;
				}

				int e2 = left.first - left.second + 1000;
				int sz2 = main_diagonal[e2].size();

				if (sz2 > 0) {
					int high = sz2 - 1, low = 0;
					if (v(bottom.first, bottom.second)) high = main_idx[bottom.first][bottom.second];
					if (v(left.first, left.second)) low = main_idx[left.first][left.second];
					int val = main_diagonal[e2][high];
					if (low > 0) val -= main_diagonal[e2][low - 1];
					cnt += val;
				}

				int e3 = top.first + top.second;
				if (e3 >= 0) {
					int sz3 = cross_diagonal[e3].size();
					if (sz3 > 0) {
						int high = sz3 - 1, low = 0;
						if (v(left.first, left.second)) high = cross_idx[left.first][left.second];
						if (v(top.first, top.second)) low = cross_idx[top.first][top.second];
						int val = cross_diagonal[e3][high];
						if (low > 0) val -= cross_diagonal[e3][low - 1];
						// cout << p << " => " << d << " :: " << val << '\n';
						cnt += val;
						
					}
				}

				int e4 = right.first + right.second;
				if (e4 >= 0) {
					int sz4 = cross_diagonal[e4].size();
					if (sz4 > 0) {
						int high = sz4 - 1, low = 0;
						if (v(bottom.first, bottom.second)) high = cross_idx[bottom.first][bottom.second];
						if (v(right.first, right.second)) low = cross_idx[right.first][right.second];
						// cout << "low => " << low << '\n';
						// cout << "high =>" << high << '\n';
						int val = cross_diagonal[e4][high];
						if (low > 0) val -= cross_diagonal[e4][low - 1];

						cnt += val;

						// cout << p << if (v(top.first, top.second) && mat[top.first][top.second]) val--;" => " << d << " :: " << val << '\n';
					}
				}

				// cout << p << " => " << d << " :: " << cnt << '\n';

				// cout << "right" << right;

				if (v(top.first, top.second) && mat[top.first][top.second]) cnt--;
				if (v(bottom.first, bottom.second) && mat[bottom.first][bottom.second]) cnt--;

				
				if (v(left.first, left.second) && mat[left.first][left.second]) cnt--;
				if (v(right.first, right.second) && mat[right.first][right.second]) cnt--;

				// cout << p << " => " << d << " :: " << cnt << '\n';

						// return 0;


				// cout << "-----------\n";
				D[d] += cnt;
			}

			
		}

		for (int i = 1; i <= N + M - 2; i++) 
			cout << D[i] / 2 << ' ';
		cout << '\n';
	}


}
