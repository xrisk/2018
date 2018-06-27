#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

typedef  long long LL;

using namespace std;

int main() {

	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector<int> vec(n);
	vector<int> sizes(m);
	set<int> lt;
	int req = n/m; long long soln = 0;

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		sizes[vec[i] % m]++;
	}

	vector<int> vec2(vec.begin(), vec.end());

	for (int i = 0; i < m; i++) {
		// sizes[i] = rem[i].size();
		if (sizes[i] < req) { 
			// cout << "inserting " << i << " and " << m + i << "\n";
			lt.insert(i); lt.insert(m + i); 
		}
	}

	// for (int i = 0; i < m; i++) {
	// 	cout << i << " -> " << sizes[i] << "\n";
	// }

	
	for (int i = 0; i < n; i++) {
		int cur = vec[i];
		if (sizes[cur % m] > req) {
			auto it = lt.upper_bound(cur % m);
			int c = *it;
			// cout << "found " << c << " for " << cur << "\n";
 			if (c >= m) c -= m;		
			vec[i] += c;
			soln += c;
			sizes[c]++;
			if (sizes[c] == req) {
				lt.erase(lt.find(c));
				lt.erase(lt.find(c + m));
			}	

		}
	}

	
	cout << soln << '\n';

	for (int i = 0; i < n; i++) {
		cout << vec[i] << ' ';
	}

	cout << '\n';
}