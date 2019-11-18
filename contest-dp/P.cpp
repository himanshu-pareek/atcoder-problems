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

const int mx = 1e5 + 5;
vector < int > g[mx];

pair < int, int > dfs (int root, int parent) {
	int white = 1, black = 1;
	for (int u : g[root]) {
		if (u != parent) {
			pair  < int, int > p = dfs (u, root);
			white = mul (white, p.first + p.second);
			black = mul (black, p.first);
		}
	}
	return make_pair (white, black);
}

int main() {
	int n, a, b;
	scanf ("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf ("%d%d", &a, &b);
		g[a].push_back (b);
		g[b].push_back (a);
	}
	pair < int, int > ans = dfs (1, -1);
	add_self (ans.first, ans.second);
	printf ("%d\n",ans.first);
	return 0;
}

