#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1e9 + 7

template < typename T >
void printVector (const vector < T > & vec) {
	for (const T x : vec) {
		cout << x << " ";
	}
	cout << endl;
}

template < typename T >
void printMatrix (const vector < vector < T > > & mat) {
	for (const vector < T > vec : mat) {
		printVector (vec);
	}
	cout << endl;
}

const ll INF = 1e18L + 5;

template < typename T >
void min_self (T& a, T b) {
	a = min (a, b);
}

template < typename T >
void max_self (T& a, T b) {
	a = max (a, b);
}

template < typename T >
void add_self (T & a, T b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

template < typename T >
void sub_self (T & a, T b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
}

int main() {
	int n;
	scanf ("%d", &n);
	vector < vector < int > > p (n, vector < int > (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf ("%d", & p[i][j]);
		}
	}
	vector < int > dp (1 << n, 0);
	dp[0] = 1;
	for (int state = 0; state < (1 << n) - 1; state++) {
		int a = __builtin_popcount (state);
		for (int b = 0; b < n; b++) {
			if (p[a][b] && !((state >> b) & 1)) {
				int mask = state ^ (1 << b);
				add_self (dp[mask], dp[state]);
			}
		}
	}
	printf ("%d\n", dp[(1 << n) - 1]);
	return 0;
}

