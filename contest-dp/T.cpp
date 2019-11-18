/**
 * Question Link: https://atcoder.jp/contests/dp/tasks/dp_t
 * Video solution: https://www.youtube.com/watch?v=FAQxdm0bTaw
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

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

const int mx = 3005;
char s[mx];
int dp[mx][mx];

int main() {
	// dp (i, j) = total permutations of numbers in the range
	// [1, i] such that last number is j

	int n;
	scanf ("%d %s", &n, s);

	// O (N ^ 3) solution
	// From here
	// dp[1][1] = 1;
	// for (int len = 2; len <= n; len++) {
	// 	for (int b = 1; b <= len; b++) {
	// 		for (int a = 1; a <= len; a++) {
	// 			int new_a = a;
	// 			if (new_a >= b) {
	// 				new_a++;
	// 			}
	// 			assert (new_a != b);
	// 			if ((new_a < b) != (s[len - 2] == '<')) continue;
	// 			add_self (dp[len][b], dp[len - 1][a]);
	// 		}
	// 	}
	// }
	// int answer = 0;
	// for (int i = 1; i <= n; i++) {
	// 	add_self (answer, dp[n][i]);
	// }
	// to here

	dp[1][1] = 1;
	for (int len = 2; len <= n; len++) {
		vector < int > pref_sum (len + 1, 0);
		for (int i = 1; i <= len; i++)  {
			pref_sum[i] = (pref_sum[i - 1] + dp[len - 1][i]) % MOD;
		}
		for (int b = 1; b <= len; b++) {
			int L, R;
			if (s[len - 2] == '<') {
				// a := 1 -> (b - 1)
				L = 1, R = b - 1;
			} else {
				L = b, R = len;
			}
			add_self (dp[len][b], (pref_sum[R] - pref_sum[L - 1] + MOD) % MOD);
			// for (int i = L; i <= R; i++) {
			// 	add_self (dp[len][b], dp[len - 1][i]);
			// }
			// for (int a = 1; a <= len; a++) {
			// 	int new_a = a;
			// 	if (new_a >= b) {
			// 		new_a++;
			// 	}
			// 	assert (new_a != b);
			// 	if ((new_a < b) != (s[len - 2] == '<')) continue;
			// 	add_self (dp[len][b], dp[len - 1][a]);
			// }
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		add_self (answer, dp[n][i]);
	}
	printf ("%d\n", answer);
	return 0;
}