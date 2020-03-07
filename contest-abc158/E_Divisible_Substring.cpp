#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

// Problem link : https://atcoder.jp/contests/abc158/tasks/abc158_e

int main() {
	int N, P; string S;
	cin >> N >> P >> S;
	assert (N == S.size());
	ll answer = 0LL;
	
	if (P == 2 || P == 5) {
		for (int i = 0; i < N; i++) {
			int current_digit = S[i] - '0';
			if (current_digit % P == 0) {
				answer += (i + 1);
			}
		}
		cout << answer << endl;
		return 0;
	}
	
	vector < int > dp (P);
	dp[(S[N - 1] - '0') % P] = 1;
	answer += dp[0];
	int pow10 = 1;
	int zero = 0;
	for (int i = N - 2; i >= 0; i--) {
		int current_digit = S[i] - '0';
		pow10 = (pow10 * 10) % P;
		int current_number = (current_digit * pow10) % P;
		zero = (zero - current_number + P) % P;
		dp[(current_number + zero) % P]++;
		answer += dp[zero];
		//cout << i << " => " << dp[zero] << endl;
	}
	cout << answer << endl;
	return 0;
}

/**
 * 55 + 6 + 5 + 1 + 1*/
