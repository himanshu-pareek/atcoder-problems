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
	int h, w;
	scanf ("%d %d", &h, &w);
	vector < string > mat (h);
	for (int i = 0; i < h; i++) {
		cin >> mat[i];
	}
	vector < vector < int > > dp (h, vector < int > (w, 0));
	vector < pair < int, int > > diffs = {{0, 1}, {1, 0}};
	dp[0][0] = 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			for (pair < int, int > diff : diffs) {
				int x = i + diff.first, y = j + diff.second;
				if (x < h && y < w && mat[x][y] == '.') {
					add_self (dp[x][y], dp[i][j]);
				}
			}
		}
	}
	// printMatrix (dp);
	printf ("%d\n", dp[h - 1][w - 1]);
	return 0;
}

