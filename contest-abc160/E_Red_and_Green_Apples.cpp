/**
 * Contest : AtCoder Beginner Contest 160
 * Contest URL : https://atcoder.jp/contests/abc160
 * Problem : E - Red and Green Apples
 * Problem URL : https://atcoder.jp/contests/abc160/tasks/abc160_e
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


void solve() {
	int x, y, A, B, C;
	cin >> x >> y >> A >> B >> C;
	vector < int > a(A), b(B), c(C);
	for (int i = 0; i < A; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < B; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < C; i++) {
		cin >> c[i];
	}
	sort (a.rbegin(), a.rend());
	sort (b.rbegin(), b.rend());
	sort (c.rbegin(), c.rend());
	priority_queue < int, vector < int > , greater < int > > pq;
	ll ans = 0LL;
	for (int i = 0; i < x; i++) {
		ans += a[i];
		pq.push (a[i]);
	}
	for (int i = 0; i < y; i++) {
		ans += b[i];
		pq.push (b[i]);
	}
	for (int x : c) {
		int y = pq.top(); pq.pop();
		if (x > y) {
			ans -= y;
			ans += x;
		}
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

