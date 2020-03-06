#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;
const int mod = 1e9 + 7;

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int mul (int a, int b) {
	return (int) (((ll) a * b) % mod);
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

pii getFirstAndLast (ll n) {
	pii p;
	p.second = n%10;
	while (n) {
		p.first = n%10;
		n = n/10;
	}
	return p;
}

int main() {
	ll N;
	cin >> N;
	ll answer = 0LL;
	for (ll A = 1; A <= N; A++) {
		ll added = 0;
		pair < int, int > p = getFirstAndLast (A);
		int x = p.first, y = p.second;
		//cout << "A = " << A << x << " " << y << endl;
		if (y == 0) continue;
		if (10 * y + x <= N) {
			added++;
		}
		for (int d = 1; d < 5; d++) {
			ll S = (N - x) / 10 - (ll) (y * pow (10, d));
			added += max (0LL, min (S + 1, (ll) pow (10, d)));
			//cout << added << endl;
		}
		// If B is of the form x (when x == y)
		if (x == y) {
			added += 1;
			//cout << "." << added << endl;
		}
		answer += added;
	}
	cout << answer << endl;
	return 0;
}

