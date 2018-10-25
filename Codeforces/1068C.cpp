// rishav.io

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <tuple>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

bool discovered[105];
int comp_id[105];
vector<LL> adj[105];

int cur_comp_id = 0;

vector<LL> complist[105];

void dfs(int u) {
	if (discovered[u]) return;
	discovered[u] = true;
	complist[cur_comp_id].push_back(u);
	comp_id[u] = cur_comp_id;
	for (LL v : adj[u]) {
		dfs(v);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int n, m; cin >> n >> m;

	vector<PLL> harm;

	for (int i = 0; i < m; i++) {
		LL x, y; cin >> x >> y;
		harm.push_back({x, y});
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (!discovered[i]) {
			cur_comp_id++;
			dfs(i);
		}
	}

	vector<PLL> mat;
	LL glob_x = 0;
	LL glob_y = 0;
	LL cur_x = 0;
	LL cur_y = 0;
	LL cur_bottom = 0;

	map<PLL, LL> global;

	vector<PLL> pos[105];


	for (int i = 1; i <= cur_comp_id; i++) {

		cur_x = 0;
		cur_y = 0;
		cur_bottom = 0;

		vector<LL> cur = complist[i];
		sort(cur.begin(), cur.end());
		vector<tuple<LL, LL, LL > > grid;
		map<PLL, LL> m;

		// cout << adj[1].size() << "----\n";
		for (LL j = 0; j < (int)cur.size(); j++) {
			LL x = cur[j];
			// cout << "x" << x << '\n';
			// cout << cur_x << " foo " << cur_y << ' ' << x << '\n';
			// cout << " ----- \n";
			grid.push_back({cur_x, cur_y, x});
			cur_y++;
			// cout << cur_x << " foo " << cur_y << ' ' << x << '\n';
			// cout << "-----\n";
			grid.push_back({cur_x, cur_y, x});
			sort(adj[x].begin(), adj[x].end());
			for (int i = 0; i < (int)adj[x].size(); i++) {
			// for (LL v : adj[x]) {
				if (j != 0 && adj[x][i] == cur[j - 1]) continue;
				if ((j + 1) < (int)cur.size() && adj[x][i] == cur[j + 1]) continue;
				LL v = adj[x][i];
				cout << "x, v => " << x << ", " << v << '\n';
				cur_y++;

				grid.push_back({cur_x, cur_y, x});
				if (x < v) {
					cur_bottom--;
					grid.push_back({cur_bottom, cur_y, x});
					m[make_pair(x, v)] = cur_bottom;				
				} else {
					LL y = m[make_pair(v, x)];
					grid.push_back({y, cur_y, x});
				}
			}
			cur_x++;
		}

		// if (cur_bottom != 0) {
		// 	for (auto& p : grid) {
		// 		grid.second += abs(cur_bottom);
		// 	}
		// }

		// cout << "bottom" << cur_bottom << '\n';

		if (cur_bottom != 0) {
			for (int i = 0; i < (int)grid.size(); i++) {
				grid[i] = { get<0>(grid[i]) + abs(cur_bottom),
							get<1>(grid[i]),
							get<2>(grid[i]) };
			}
		}

		LL new_glob_x = -1;
		LL new_glob_y = -1;
		for (auto& p : grid) {

			LL type = get<2>(p);
			pos[type].push_back({
				get<0>(p) + glob_x,
				get<1>(p) + glob_y,
			});
			// global.push_back({glob_x + p.first, glob_y + p.second});
			new_glob_x = max(new_glob_x, glob_x + get<0>(p) + 1);
			new_glob_y = max(new_glob_y, glob_y + get<1>(p) + 1);
		}

		glob_x = new_glob_x;
		glob_y = new_glob_y;
	}

	for (int i = 1; i <= n; i++) {
		cout << pos[i].size() << '\n';
		for (PLL p : pos[i]) {
			cout << p.first << ' ' << p.second << '\n';
		}
	}



}
