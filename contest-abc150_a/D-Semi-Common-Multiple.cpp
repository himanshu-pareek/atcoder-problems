#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

ll lcm (ll a, int b) {
	int g = __gcd ((int) a, b);
	ll l = a * b;
	l /= g;
	return l;
}

int main() {
	ios::sync_with_stdio (false);
	int n, m;
	cin >> n >> m;
	vector < int > a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int & x : a) x >>= 1;
	ll l = 1;
	for (int i = 0; i < n; i++) {
		l = lcm (l, a[i]);
		if (l > m) {
			cout << 0 << endl;
			return 0;
		}
	}
	bool possible = true;
	for (int x : a) {
		if ((l / x) % 2 == 0) {
			possible = false;
			break;
		}
	}
	if (!possible) {
		cout << 0 << endl;
		return 0;
	}
	n = m / l;
	n = (n + 1) / 2;
	cout << n << endl;
	return 0;
}

