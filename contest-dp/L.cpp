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

void add_self (int & a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int main() {
	int n;
	scanf ("%d", &n);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", &x);
	vector < vector < ll > > dp (3005, vector < ll > (3005));
	for (int l = n - 1; l >= 0; l--) {
		for (int r = l; r < n; r++){
			if (l == r) {
				dp[l][r] = a[l];
			} else {
				dp[l][r] = max (a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
			}
		}
	}
	printf ("%lld\n", dp[0][n - 1]);
	return 0;
}

