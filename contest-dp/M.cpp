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

int main() {
	int n, k;
	scanf ("%d %d", &n, &k);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", & x);
	vector < int > dp (k + 1);
	dp[0] = 1;
	for (int child = 0; child < n; child++) {
		// upper bound = a[child]
		// lower bound = 0
		vector < int > vec (k + 1, 0);
		for (int used = k; used >= 0; used--) {
			// used -> #used (distributed) candies
			// toGive >= 0 and toGive <= a[child] and toGive + used <= k
			// => toGive is in [0, min (a[child], k - used)]
			int to = min (a[child], k - used);
			// x = toGive + used
			// toGive = 1 -> toGive + used = used + 1
			// toGive = to -> toGive + used = used + to
			int y = used + 1, z = used + to;
			int temp = dp[used];

			// for (int x = y; x <= z; x++) {
			// 	add_self (dp[x], temp);
			// }
			if (y <= z) {
				add_self (vec[y], temp);
				if (z < k) sub_self (vec[z + 1], temp);
			}
		}
		int prefix_sum = 0;
		for (int i = 0; i <= k; i++) {
			add_self (prefix_sum, vec[i]);
			add_self (dp[i], prefix_sum);
		}
	}
	printf ("%d\n", dp[k]);
	return 0;
}

