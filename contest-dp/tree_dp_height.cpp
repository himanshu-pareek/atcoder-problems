#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void max_self (int & a, int b) {
	a = max (a, b);
}

void dfs1 (vector < vector < int > > & g, vector < int > & in, int u, int p) {
	int mx = -1;
	for (int v : g[u]) {
		if (v == p) continue;
		dfs1 (g, in, v, u);
		max_self (mx, in[v]);
	}
	in[u] = 1 + mx;
}

void dfs2 (vector < vector < int > >  & g, vector < int > & out, vector < int > & in, int u, int p) {
	// find max (in[v]) for v in children of u
	int max1 (-1), max2 (-1);
	for (int v : g[u]) {
		if (v == p) continue;
		if (in[v] >= max1) {
			max2 = max1; max1 = in[v];
		} else if (in[v] >= max2) {
			max2 = in[v];
		}
	}

	// maximum value - max1
	// second maximum value - max2
	for (int v : g[u]) {
		if (v == p) continue;
		int use = (in[v] == max1) ? max2 : max1;
		out[v] = max (1 + out[u], 2 + use);
		dfs2 (g, out, in, v, u);
	}
}

int main() {
	int n, m;
	scanf ("%d %d", &n, &m);
	vector < vector < int > > g (n);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf ("%d %d", &u, &v);
		u--; v--;
		g[u].push_back (v); g[v].push_back (u);
	}
	vector < int > in (n), out (n);

	dfs1 (g, in, 0, -1);
	dfs2 (g, out, in, 0, -1);

	for (int i = 0; i < n; i++) {
		printf ("%d -> %d\n", i + 1, max (in[i], out[i]));
	}

	return 0;
}
