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


int main() {
	int D; char K[10005];
	scanf ("%s %d", K, &D);
	vector < vector < int > > dp (D, vector < int > (2));
	// dp[i][j] := answer for i=sum%D till now [ j = 1 => 
	// current number is already smaller than actual number]
	dp[0][0] = 1;
	// printMatrix (dp);
	int len = strlen (K);
	for (int i = 0; i < len; i++) {
		int digit = K[i] - '0';
		vector < vector < int > > new_dp (D, vector < int > (2));
		for (int sum = 0; sum < D; sum++) {
			for (bool already_smaller : {false, true}) {
				int end = digit;
				if (already_smaller) end = 9;
				for (int d = 0; d <= end; d++) {
					int smaller = already_smaller || d < digit;
					add_self (new_dp[(sum + d) % D][smaller], dp[sum][already_smaller]);
				}
			}
		}
		dp = new_dp;
	}
	// printMatrix (dp);
	int answer = dp[0][0];
	add_self (answer, dp[0][1]);
	sub_self (answer, 1);
	printf ("%d\n", answer);
	return 0;
}