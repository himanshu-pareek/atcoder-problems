#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mod = 1e9 + 7;

int mul (int a, int b) {
	return (int) (((ll) a *b ) % mod);
}

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int power (int a, int k) {
	int ans = 1;
	while (k >= 1) {
		if (k & 1) ans = mul (ans, a);
		a = mul (a, a);
		k >>= 1;
	}
	return ans;
}

int inverse (int a) {
	return power (a, mod - 2);
}

int main() {
	ios::sync_with_stdio (false);
	int n;
	cin >> n;
	vector < int > c (n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort (c.begin(), c.end());
	int ans = 0;
	int upto = n;
	int r = 0;
	int ncr = 1;
	for (int i = 0; i < n; i++) {
		int x = mul (upto, upto + 1);
		x = mul (x, inverse (2));
		upto--;
		x = mul (x, ncr);
		// r++;
		ncr = mul (ncr, n - r);
		ncr = mul (ncr, inverse (r + 1));
		x = mul (x, c[i]);
		add_self (ans, x);
	}
	cout << ans << endl;
	return 0;
}

