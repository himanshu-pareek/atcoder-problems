#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int , int >;

template < typename T >
void min_self (T & a, T b) {
	if (a > b) a = b;
}

const int mx = 301;
const ll inf = 1e18 - 1;

void solve() {
	int n, k;
	scanf ("%d %d", &n, &k);
	ll h[mx];
	for (int i = 0; i < n; i++) {
		scanf ("%lld", &h[i]);
	}
	
	ll dp[mx][mx];
	for (int i = 0; i < mx; i++) {
		for (int j = 1; j < mx; j++) {
			dp[i][j] = inf;
		}
	}
		
	for (int i = 0; i < n; i++) dp[i][1] = h[i];
	
	for (int x = 1; x < n; x++) {
		for (int y = 2; y < n - k + 1; y++) {
			for (int i = 0; i < x; i++) {
				min_self (dp[x][y], dp[i][y - 1] + max (0LL, h[x] - h[i]));
			}
		}
	}
	
	ll answer = inf;
	
	for (int i = 0; i < n; i++) {
		min_self (answer, dp[i][n - k]);
	}
	
	printf ("%lld\n", answer);
}

int main() {
	solve();
	return 0;
}
