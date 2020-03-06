#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	string N; int K;
	cin >> N;
	scanf ("%d", &K);
	vector < vector < ll > > dp (K + 1, vector < ll > (2));
	const int n = N.size();
	dp[0][0] = 1LL;
	//cout << "n = " << n << endl;
	for (int i = 0; i < n; i++) {
		vector < vector < ll > > new_dp (K + 1, vector < ll > (2, 0));
		for (int current_digit = 0; current_digit < 10; current_digit++) {
			int end = N[i] - '0';
			for (bool already_smaller : {false, true}) {
				if (already_smaller) end = 9;
				for (int next_digit = 0; next_digit <= end; next_digit++) {
					bool smaller = already_smaller || (next_digit < end);
					int endK = (next_digit == 0) ? K : (K - 1);
					for (int k = 0; k <= endK; k++) {
						if (next_digit) {
							new_dp[k + 1][smaller] += dp[k][already_smaller];
						} else {
							new_dp[k][smaller] += dp[k][already_smaller];
						}
					}
				}
			}
		}
		for (int i = 0; i <= K; i++) {
			for (bool b : {true, false}) {
				new_dp[i][b] /= 10;
			}
		}
		dp = new_dp;
	}
	//for (vector < ll > d : dp) {
		//for (ll x : d) {
			//cout << x << " ";
		//}
		//cout << endl;
	//}
	//cout << endl;
	int cnt = 0;
	for (int c : N) {
		cnt += (c != '0');
	}
	cout << (dp[K][true] + (cnt == K)) << endl;
	return 0;
}
