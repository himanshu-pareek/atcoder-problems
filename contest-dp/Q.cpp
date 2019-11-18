#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

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

ll mul (int a, int b) {
	return ((ll) a * b) % MOD;
}

int main() {
	int n;
	scanf ("%d", &n);
	vector < int > h (n), a (n);
	for (int & x : h) scanf ("%d", & x);
	for (int & x : a) scanf ("%d", & x);
	int base = 1;
	while (base <= n) {
		base <<= 1;
	}
	vector < ll > tree (2 * base);
	vector < ll > dp (n + 1);
	for (int i = 0; i < n; i++) {
		// max dp[j] for j in [0, h[i] - 1]
		// query segment tree
		int x = h[i] + base;
		ll best = 0;
		while (x > 1) {
			if (x % 2) {
				max_self (best, tree[x - 1]);
			}
			x >>= 1;
		}
		dp[h[i]] = best + a[i];
		// update segment tree
		for (int j = base + h[i]; j >= 1; j >>= 1) {
			max_self (tree[j], dp[h[i]]);
		}

		// for (int height = 0; height < h[i]; height++) {
		// 	max_self (dp[h[i]], dp[height] + a[i]);
		// }
	}
	ll answer = 0;
	for (ll x : dp) max_self (answer, x);
	printf ("%lld\n", answer);
	return 0;
}