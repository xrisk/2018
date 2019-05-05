#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

typedef long long LL;

const LL NMAX = 1e9 + 1e6 + 5;
const int BLK = 320;

LL blk_sol[BLK];

using namespace std;

vector<int> big;

// https://www.geeksforgeeks.org/segmented-sieve/

void simpleSieve(int limit, vector<int> &prime) {
  // Create a boolean array "mark[0..n-1]" and initialize
  // all entries of it as true. A value in mark[p] will
  // finally be false if 'p' is Not a prime, else true.
  bool mark[limit + 1];
  memset(mark, true, sizeof(mark));

  for (int p = 2; p * p < limit; p++) {
    // If p is not changed, then it is a prime
    if (mark[p] == true) {
      // Update all multiples of p
      for (int i = p * 2; i < limit; i += p) mark[i] = false;
    }
  }

  // Print all prime numbers and store them in prime
  for (int p = 2; p < limit; p++) {
    if (mark[p] == true) {
      prime.push_back(p);
      pr.push_back(p);
    }
  }
}

// Prints all prime numbers smaller than 'n'
void segmentedSieve(int lo, int hi, vector<int> &small) {
  // Compute all primes smaller than or equal
  // to square root of n using simple sieve

  int low = lo;
  int high = hi;

  bool mark[high - lo + 5];
  memset(mark, true, sizeof(mark));

  // Use the found primes by simpleSieve() to find
  // primes in current range
  for (int i = 0; i < small.size(); i++) {
    // Find the minimum number in [low..high] that is
    // a multiple of prime[i] (divisible by prime[i])
    // For example, if low is 31 and prime[i] is 3,
    // we start with 33.
    int loLim = floor(low / small[i]) * small[i];
    if (loLim < low) loLim += prime[i];

    /* Mark multiples of prime[i] in [low..high]:
        We are marking j - low for j, i.e. each number
        in range [low, high] is mapped to [0, high-low]
        so if range is [50, 100] marking 50 corresponds
        to marking 0, marking 51 corresponds to 1 and
        so on. In this way we need to allocate space only
        for range */
    for (int j = loLim; j < high; j += small[i]) mark[j - low] = false;
  }

  // Numbers which are not marked as false are prime
  for (int i = low; i < high; i++)
    if (mark[i - low] == true) big.push_back(i);

  // Update low and high for next segment
}

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N, Q;
  cin >> N >> Q;
  vector<int> vec(N);

  int mx = INT_MIN;
  int mn = INT_MAX;

  for (int i = 0; i < N; i++) {
    cin >> vec[i];
    if (vec[i] > mx) mx = vec[i];
    if (vec[i] < mn) mn = vec[i];
  }

  vector<int> small;
  mx++;

  int limit = floor(sqrt(NMAX)) + 1;
  int range = mx - mn + 1;

  simpleSieve(limit, small);
  segmentedSieve(mn, mx, small);

  int lo = 0;
  int hi = BLK;

  while (lo < N) {
    if (hi > N) hi = N;
    LL r = 0;
    for (int i = lo; i < hi; i++) r += vec[i];
    blk_sol[lo / BLK] = r;
    lo += BLK;
    hi += BLK;
  }

  while (Q--) {
    int o, l, r;
    cin >> o >> l >> r;
    if (o == 1) {
      for (int) }
  }
}