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

int mul (int a, int b) {
	return ((ll) a * b) % MOD;
}

struct Matrix {
	vector < vector < int > > t;
	Matrix (int m, int n) {
		t.resize (m, vector < int > (n));
	}

	Matrix operator * (const Matrix & b) const {
		Matrix c = Matrix(t.size(), b.t[0].size());
		for (int i = 0; i < c.t.size(); i++) {
			for (int j = 0; j < c.t[0].size(); j++) {
				for (int k = 0; k < t[0].size(); k++) {
					add_self (c.t[i][j], mul (t[i][k], b.t[k][j]));
				}
			}
		}
		return c;
	}
};

int main() {
	int n; ll K;
	scanf ("%d %lld", &n, &K);
	vector < vector < int > > g (n, vector < int > (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf ("%d", &g[i][j]);
		}
	}

	Matrix m = Matrix (n, n);
	Matrix answer = Matrix (n, n);
	m.t = g;
	for (int i = 0; i < n; i++) answer.t[i][i] = 1;
	while (K >= 1) {
		if (K % 2) {
			answer = answer * m;
		}
		m = m * m;
		K /= 2;
	}

	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			add_self (total, answer.t[i][j]);
		}
	}

	printf ("%d\n", total);

	// vector < ll > dp (n, 1);

	// for (ll k = 1; k <= K; k++) {
	// 	vector < ll > new_dp (n);
	// 	for (int i = 0; i < n; i++) {
	// 		for (int j = 0; j < n; j++) {
	// 			if (g[i][j]) {
	// 				add_self (new_dp[j], dp[i]);
	// 			}
	// 		}
	// 	}
	// 	dp = new_dp;
	// }

	// ll answer = 0;
	// for (int i = 0; i < n; i++) {
	// 	add_self (answer, dp[i]);
	// }

	// printf ("%lld\n", answer);
	
	return 0;
}