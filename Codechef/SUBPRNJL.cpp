// CPP program to implement k-th order statistics 
#include <bits/stdc++.h> 
using namespace std; 

const int MAX = 9000; 

// https://www.geeksforgeeks.org/merge-sort-tree-for-range-order-statistics/

// Constructs a segment tree and stores tree[] 
void buildTree(int treeIndex, int l, int r, 
	vector<pair<int, int> > a, vector<int> tree[]) 
{ 

	/* l => start of range, 
		r => ending of a range 
		treeIndex => index in the Segment Tree/Merge 
					Sort Tree */

	/* leaf node */
	if (l == r) { 
		tree[treeIndex].push_back(a[l].second); 
		return; 
	} 

	int mid = (l + r) / 2; 

	/* building left subtree */
	buildTree(2 * treeIndex, l, mid, a, tree); 

	/* building left subtree */
	buildTree(2 * treeIndex + 1, mid + 1, r, a, tree); 

	/* merging left and right child in sorted order */
	merge(tree[2 * treeIndex].begin(), 
		tree[2 * treeIndex].end(), 
		tree[2 * treeIndex + 1].begin(), 
		tree[2 * treeIndex + 1].end(), 
		back_inserter(tree[treeIndex])); 
} 

// Returns the Kth smallest number in query range 
int queryRec(int segmentStart, int segmentEnd, 
			int queryStart, int queryEnd, int treeIndex, 
				int K, vector<int> tree[]) 
{ 
	/* 
		segmentStart => start of a Segment, 
		segmentEnd => ending of a Segment, 
		queryStart => start of a query range, 
		queryEnd	 => ending of a query range, 
		treeIndex => index in the Segment 
						Tree/Merge Sort Tree, 
		K => kth smallest number to find */

	if (segmentStart == segmentEnd) 
		return tree[treeIndex][0]; 
	
	int mid = (segmentStart + segmentEnd) / 2; 

	// finds the last index in the segment 
	// which is <= queryEnd 
	int last_in_query_range = 
			(upper_bound(tree[2 * treeIndex].begin(), 
						tree[2 * treeIndex].end(), 
										queryEnd) 
					- tree[2 * treeIndex].begin()); 

	// finds the first index in the segment 
	// which is >= queryStart 
	int first_in_query_range = 
				(lower_bound(tree[2 * treeIndex].begin(), 
							tree[2 * treeIndex].end(), 
										queryStart) 
						- tree[2 * treeIndex].begin()); 

	int M = last_in_query_range - first_in_query_range; 

	if (M >= K) { 

		// Kth smallest is in left subtree, 
		// so recursively call left subtree for Kth 
		// smallest number 
		return queryRec(segmentStart, mid, queryStart, 
					queryEnd, 2 * treeIndex, K, tree); 
	} 

	else { 

		// Kth smallest is in right subtree, 
		// so recursively call right subtree for the 
		// (K-M)th smallest number 
		return queryRec(mid + 1, segmentEnd, queryStart, 
			queryEnd, 2 * treeIndex + 1, K - M, tree); 
	} 
} 

// A wrapper over query() 
int query(int queryStart, int queryEnd, int K, int n, 
		vector<pair<int, int> > a, vector<int> tree[]) 
{ 

	return queryRec(0, n - 1, queryStart - 1, queryEnd - 1, 
											1, K, tree); 
} 

int counts[2005][2005];

// Driver code 
int main() 
{ 	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

#ifdef __APPLE__
	freopen("input.txt", "r", stdin);
#endif

	int T; cin >> T;

	while (T--) {

		int n, k; cin >> n >> k;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		vector<pair<int, int>> v; 
		for (int i = 0; i < n; i++) { 
			v.push_back(make_pair(arr[i], i)); 
		} 

		// sort the vector 
		sort(v.begin(), v.end()); 

		// Construct segment tree in tree[] 
		vector<int> tree[MAX]; 
		buildTree(1, 0, n - 1, v, tree); 

		// // Answer queries 
		// // kSmallestIndex hold the index of the kth smallest number 
		// int kSmallestIndex = query(2, 5, 2, n, v, tree); 
		// cout << arr[kSmallestIndex] << endl; 

		// kSmallestIndex = query(1, 6, 4, n, v, tree); 
		// cout << arr[kSmallestIndex] << endl; 

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= 2000; ++j) {
				if (i == 0) counts[i][j] = 0;
				else		counts[i][j] = counts[i - 1][j];
			}
			counts[i][arr[i]]++;
		}

		int answer = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				int len = j - i + 1;
				int m = k / len;
				if (k % len != 0) m++;
				int real_index = (k - 1) / m;
				int X = arr[query(i + 1, j + 1, real_index + 1, n, v, tree)];
				int F = counts[j][X];
				if (i != 0) F -= counts[i - 1][X];

				int S = counts[j][F];
				if (i != 0) S -= counts[i - 1][S];

				if (S != 0) {
					cout << i << " " << j << " " << real_index << " " << 
							X << " " << F << " " << S << endl;
					answer++;
				}
			}
		}

		cout << answer << '\n';

	}

	return 0; 
} 

