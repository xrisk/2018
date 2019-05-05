// rishav.io

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <climits>
#include <utility>

using namespace std;

typedef long long LL;

int main() {

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int N; cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	auto last = unique(vec.begin(), vec.end());
	if (last - 2 < vec.begin()) cout << "0\n";
	else cout << *(last - 2) << '\n';


	
}