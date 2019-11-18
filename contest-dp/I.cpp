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
	double p;
	scanf ("%d", &n);
	vector < double > dp (n + 1, 0.0);
	dp[0] = 1.0;
	for (int coin = 1; coin <= n; coin++) {
		scanf ("%lf", &p);
		for (int i = coin; i >= 0; i--) {
			dp[i] = (i == 0 ? 0 : dp[i - 1] * p) + dp[i] * (1.0 - p);
		}
	}
	double answer = 0.0;
	for (int i = n / 2 + 1; i <= n; i++) {
		answer += dp[i];
	}
	printf ("%.10lf\n", answer);
	return 0;
}

