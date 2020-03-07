#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

// Problem link : https://atcoder.jp/contests/abc158/tasks/abc158_f

// MODULAR ARITHMATIC
const int mod = 998244353;

template < typename T >
void add_self (T & a, T b) {
	a += b;
	if (a >= mod) a -= mod;
}

int main() {
	int n;
	cin >> n;
	vector < pii > a (n);
	for (pii & p : a) {
		cin >> p.first >> p.second;
	}
	sort (a.begin(), a.end(), [&] (const pii & p1, const pii & p2) {
		return p1.first < p2.first;
	});
	vector < int > dp (n + 1);
	stack < int > s;
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		// calculate j
		while (!s.empty() && a[s.top()].first < (long) a[i].first + a[i].second) {
			s.pop();
		}
		int j = n;
		if (!s.empty()) j = s.top();
		s.push (i);
		dp[i] = dp[i + 1];
		add_self (dp[i], dp[j]);
	}
	
	cout << dp[0] << endl;
		
	return 0;
}

/**
 * 55 + 6 + 5 + 1 + 1*/
