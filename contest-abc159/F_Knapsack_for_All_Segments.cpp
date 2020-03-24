/**
 * Contest : AtCoder Beginner Contest 159
 * Contest URL : https://atcoder.jp/contests/abc159/
 * Problem : F - Knapsack for All Segments
 * Problem URL : https://atcoder.jp/contests/abc159/tasks/abc159_f
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

const int mod = 998244353;

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int mul (int a, int b) {
	return (ll) a * b % mod;
}

int main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	int n, s;
	cin >> n >> s;
	vector < int > a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int answer = 0;
	vector < int > dp (s + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] < s) {
			add_self (answer, mul (n - i, dp[s - a[i]]));
		}
		for (int j = s - a[i]; j >= 1; j--) {
			add_self (dp[j + a[i]], dp[j]);
		}
		
		if (a[i] <= s) {
			add_self (dp[a[i]], i + 1);
		}
		if (a[i] == s) {
			add_self (answer, mul (i + 1, n - i));
		}
	}
	cout << answer << endl;
	return 0;
}

