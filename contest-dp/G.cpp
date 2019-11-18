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

const ll INF = 1e18L + 5;

template < typename T >
void min_self (T& a, T b) {
	a = min (a, b);
}

template < typename T >
void max_self (T& a, T b) {
	a = max (a, b);
}

const int mx = 1e5 + 5;
vector < int > g[mx];
int in_degree[mx];
int dist[mx];
bool visited[mx];

void dfs (int s) {
	visited[s] = true;
	for (int u : g[s]) {
		dist[u] = max (dist[u], 1 + dist[s]);
		in_degree[u]--;
		if (in_degree[u] == 0) {
			dfs (u);
		}
	}
}

int main() {
	int n, m, x, y;
	scanf ("%d %d", &n, &m);
	while (m--) {
		scanf ("%d %d", &x, &y);
		g[x].push_back (y);
		in_degree[y]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && in_degree[i] == 0) {
			dfs (i);
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		max_self (answer, dist[i]);
	}
	cout << answer << endl;
	return 0;
}

