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
	int N;
	scanf ("%d", &N);
	vector < int > a (N);
	for (int & x : a) scanf ("%d", & x);
	vector < ll > sums (N, 0);
	sums[0] = a[0];
	for (int i = 1; i < N; i++) {
		sums[i] = sums[i - 1] + a[i];
	}
	vector < vector < ll > > dp (N, vector < ll > (N, INF));
	for (int i = 0; i < N; i++) dp[i][i] = 0;
	for (int len = 2; len <= N; len++) {
		for (int i = 0; i <= N - len; i++) {
			int j = i + len - 1;
			if (len == 2) {
				dp[i][j] = (ll) a[i] + (ll) a[j];
				continue;
			}
			for (int k = i; k < j; k++) {
				dp[i][j] = min (dp[i][j], dp[i][k] + dp[k + 1][j] + sums[j] - sums[i] + a[i]);
			}
		}
	}
	printf ("%lld\n", dp[0][N - 1]);
	return 0;
}

