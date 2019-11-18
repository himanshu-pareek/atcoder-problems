/**
 * Question Link: https://atcoder.jp/contests/dp/tasks/dp_t
 * Video solution: https://www.youtube.com/watch?v=FAQxdm0bTaw
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD;
#define pii pair < int, int >

void printMatrix (const vector < vector < int > > & mat) {
	for (const vector < int > vec : mat) {
		for (const int x : vec) {
			cout << x << " ";
		}
		cout << endl;
	}
}

void add_self (int & a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

void sub_self (int & a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
}

int add (int a, int b) {
	int c = a + b;
	if (c >= MOD) {
		c -= MOD;
	}
	return c;
}

int mul (int a, int b) {
	return ((ll) a * b) % MOD;
}

const int mx = 1e5 + 5;
vector < int > edges [mx], children[mx];
vector < pii > downs[mx], prefix[mx], suffix[mx];
pair < int, int > down [mx], up [mx];
// black, white
#define all_white first
#define something_black second

pii merge (pii a, pii b) {
	pii p;
	p.all_white = mul (a.all_white, b.all_white);
	p.something_black = add (mul (a.something_black, add (b.all_white, b.something_black),
							mul (b.something_black, a.all_white));
	return p;
}

void dfs2 (int u, int p) {


void dfs1 (int u, int p) {
	pii p{1, 0};
	for (int v : edges[u]) {
		if (v == p) continue;
		children[u].push_back (v);
		dfs1 (v, u);
		p = merge (p, down[v]);
		downs[u].push_back (down[v]);
		//down[u].black = mul (down[u].black, add (down[v].black + down[v].white));
		//down[u].white = mul (down[u].white, down[v].white);
	}
	int white = p.all_white;
	int black = add (p.all_white + p.something_black);
	down[a] = {white, black};
}

void dfs2 (int u, int p) {



int main() {
	int n, u, v;
	scanf ("%d%d", &n, &MOD);
	for (int i = 0; i < n; i++) {
		scanf ("%d%d", &u, &v);
		edges[u].push_back (v); edges[v].push_back (u);
	}
	dfs (1, -1);
	for (int u = 1; u <= n; u++) {
		pii p{1, 0};
		int k = downs[u].size();
		assert (k == children[u].size());
		for (int i = 0; i < k; i++) {
			p = merge (p, downs[u][i]);
			prefix[u].push_back (p);
		}
		p = {1, 0};
		for (int i = k - 1; i >= 0; i--) {
			p = merge (p, downs[u][i]);
			suffix[u].push_back (p);
		}
		reverse (suffix[u].begin(), suffix[u].end());
	}
	return 0;
}
