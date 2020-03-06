#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mod = 1e9 + 7;

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int mul (int a, int b) {
	return (int) (((ll) a * b) % mod);
}

int power (int a, int k) {
	int ans = 1;
	while (k >= 1) {
		if (k & 1) ans = mul (ans, a);
		a = mul (a, a);
		k >>= 1;
	}
	return ans;
}

template < typename T >
void max_self (T & a, T b) {
	if (a < b) a = b;
}

int inverse (int a) {
	return power (a, mod - 2);
}

int distance_square (pii p, pii q) {
	return (p.first - q.first) * (p.first - q.first)
			+ (p.second - q.second) * (p.second - q.second);
}

double makeSide (pii p, pii q) {
	int ds = distance_square (p, q);
	return (double) sqrt (1.0 * ds);
}

struct Triangle {
	double a;
	double b;
	double c;
};

double calDiameter (Triangle t) {
	double a = t.a, b = t.b, c = t.c;
	double s = (a + b + c) / 2;
	double x = a * b * c * 0.5;
	double y = s * (s - a) * (s - b) * (s - c);
	y = sqrt (y);
	return x / y;
}

int main() {
	//ios::sync_with_stdio (false);
	int n;
	cin >> n;
	vector < pii > a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	if (n == 2) {
		printf ("%.9lf\n", makeSide (a[0], a[1]) * 0.5);
		return 0;
	}
	vector < double > sides (n);
	for (int i = 0; i < n; i++) {
		sides[i] = makeSide (a[i], a[(i + 1) % n]);
	}
	vector < Triangle > triangles;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				triangles.push_back ({sides[i], sides[j], sides[k]});
			}
		}
	}
	double diameter = 0.0;
	for (Triangle t : triangles) {
		max_self (diameter, calDiameter (t));
	}
	diameter = diameter * 0.5;
	printf ("%.9lf\n", diameter);
	return 0;
}

