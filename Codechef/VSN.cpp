#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>

typedef long long LL;

const int ITER = 200;

using namespace std;

struct v3 {
	double 	x, y, z;
	v3 () {

	}
	v3 (double a, double b, double c) {
		x = a; y = b; z = c;
	}
	double dot(v3 another) {
		return x * another.x + y * another.y + z * another.z;
	}
	v3 operator+(v3 another) {
		return v3 ( x + another.x , y + another.y , z + another.z );
	}
	v3 operator-(v3 another) {
		return v3 ( x - another.x , y - another.y , z - another.z );
	}
	v3 operator/(double g) {
		return v3 ( x / g, y / g, z / g);
	}
	void operator/=(double g) {
		x /= g; y /= g; z /= g;
	}
	v3 operator*(double g) {
		return v3 (x * g, y * g, z * g);
	}
	double mag() {
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}
	friend istream& operator>>(istream& o, v3 &another) {
		o >> another.x >> another.y >> another.z;
		return o;
	}
	friend ostream& operator<<(ostream& o, v3 &another) {
		o << "(" << another.x << ", " << another.y << ", " << another.z << ") ";
		return o;
	}
};

int main() {
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(false);
	// cin.tie(0);


	int T; cin >> T;
	while (T--) {
		v3 p, q, d, c; double r;
		cin >> p >> q >> d >> c;
		cin >> r;	

		// cout << p <<  q << d << c << "\n";

		double lo = 0;
		double hi = 1e9;

		for (int it = 0; it < ITER; it++) {
			double mid = (lo + hi) / 2;
			v3 q_cur = q + d * mid;
			// cout << q_cur << "\n";
			v3 L = q_cur - p;
			L /= L.mag();
			double t1 = pow(L.dot(p - c), 2);
			double t2 = pow((p - c).mag(), 2);
			double t3 = pow(r, 2);
			double res = t1 - t2 + t3;
			// cout << t1 << " " << t2 << " " << t3 << "\n";
			if (res <= 1e-15) {
				hi = mid;
			} else {
				lo = mid;
			}
		}

		cout << fixed << setprecision(15)  << lo << "\n";
	}
}