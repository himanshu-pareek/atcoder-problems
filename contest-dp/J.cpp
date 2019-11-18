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

const int mx = 305;
double p[mx][mx][mx], dp[mx][mx][mx];

int main() {
	int n, x;
	scanf ("%d", &n);
	vector < int > count (4, 0);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		++count[x];
	}
	dp[count[1]][count[2]][count[3]] = 0;
	p[count[1]][count[2]][count[3]] = 1.0;
	for (int c = n; c >= 0; c--) {
		for (int b = n; b >= 0; b--) {
			for (int a = n; a >= 0; a--) {

				if (a == 0 && b == 0 && c == 0) continue;
				if (a + b + c > n) continue;

				double p_waste = (double) (n - (a + b + c)) / (double) n;
				double expected_waste = 1.0 / (1.0 - p_waste);
				dp[a][b][c] += p[a][b][c] * expected_waste;

				if (a != 0) {
					double pa = (double) a / (a + b + c);
					p[a - 1][b][c] += p[a][b][c] * pa;
					dp[a - 1][b][c] += dp[a][b][c] * pa;
				}
				if (b != 0) {
					double pb = (double) b / (a + b + c);
					p[a + 1][b - 1][c] += p[a][b][c] * pb;
					dp[a + 1][b - 1][c] += dp[a][b][c] * pb;
				}
				if (c != 0) {
					double pc = (double) c / (a + b + c);
					p[a][b + 1][c - 1] += p[a][b][c] * pc;
					dp[a][b + 1][c - 1] += dp[a][b][c] * pc;
				}
			}
		}
	}
	// printMatrix (p[1]);
	// printMatrix (dp[1]);
	printf ("%.10lf\n", dp[0][0][0]);
	return 0;
}

