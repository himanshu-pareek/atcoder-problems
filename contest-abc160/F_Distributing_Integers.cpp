/**
 * Contest : AtCoder Beginner Contest 160
 * Contest URL : https://atcoder.jp/contests/abc160
 * Problem : F - Distributing Integers
 * Problem URL : https://atcoder.jp/contests/abc160/tasks/abc160_f
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

// This section is for Policy Based Data Structure, more precisely Ordered Set.
// All Functions of set works here, in addition we have order_of_key() and find_by_order() function. find_by_order() returns iterator
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<functional>
using namespace __gnu_pbds;

// 1. Custom Set
template < class T, class COMP >
using custom_set = tree < T, null_type, COMP, rb_tree_tag, tree_order_statistics_node_update >;

// 2. Ordered Set
template < class T >
using ordered_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;

// 3. Ordered Multi Set
// For storing multiple occurance of same value we need to use pair. In pair first value is our key and second is useless count variable.
// order_of_key(make_pair(key, 0)) returns first occurance of a value, order_of_key(make_pair(key, INT_MAX)) returns last occurance.
template < class T >
using ordered_multiset = tree < pair < T, int >, null_type, less < pair < T, int > >, rb_tree_tag, tree_order_statistics_node_update >;

// 4. Ordered Map
template < class T, class U >
using ordered_map = tree < T, U, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
// Policy End

const int mod = 1e9 + 7;
void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}
void sub_self (int & a, int b) {
	a -= b;
	if (a < 0) a += mod;
}
int mul (int a, int b) {
	return (ll) a * b % mod;
}
int power (int a, int k) {
	int ans = 1;
	while (k > 0) {
		if (k & 1) ans = mul (ans, a);
		a = mul (a, a);
		k >>= 1;
	}
	return ans;
}
int inverse (int a) {
	return power (a, mod - 2);
}

const int mx = 2e5 + 5;
int fact[mx], inv_fact[mx];

void solve() {
	int n, u, v;
	cin >> n;
	vector < vector < int > > g (n);
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		u--, v--;
		g[u].push_back (v);
		g[v].push_back (u);
	}
	vector < int > dp1 (n), dp2 (n), size (n);
	std::function < void (int, int ) > dfs = [&] (int u, int p) {
		size[u] = 1;
		int s = 1;
		for (int v : g[u]) {
			if (v != p) {
				dfs (v, u);
				size[u] += size[v];
				s = mul (s, mul (dp1[v], inv_fact[size[v]]));
			}
		}
		dp1[u] = mul (fact[size[u] - 1], s);
	};
	std::function < void (int, int) > dfs2 = [&] (int u, int p) {
		if (p != -1) {
			int f = fact[n - 1 - size[u]];
			f = mul (f, fact[size[u]]);
			f = mul (f, inverse (dp1[u]));
			f = mul (dp2[p], f);
			int s = mul (f, inv_fact[n - size[u]]);
			for (int v : g[u]) {
				if (v != p) {
					s = mul (s, mul (dp1[v], inv_fact[size[v]]));
				}
			}
			dp1[u] = mul (fact[n - 1], s);
		}
		dp2[u] = mul (dp1[u], inv_fact[n - 1]);
		for (int v : g[u]) {
			if (v != p)
				dfs2 (v, u);
		}
	};
	dfs (0, -1);
	dfs2 (0, -1);
	for (int i = 0; i < n; i++) {
		cout << dp1[i] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	int t = 1;
	fact[0] = inv_fact[0] = 1;
	for (int i = 1; i < mx; i++) {
		fact[i] = mul (fact[i - 1], i);
		inv_fact[i] = mul (inv_fact[i - 1], inverse (i));
	}
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

