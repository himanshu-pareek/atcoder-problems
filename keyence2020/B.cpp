#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < long, long >;

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

int main() {
	//cout << INT_MAX << endl;
	//cout << 2e9 << endl;
	int n, x, l;
	cin >> n;
	vector < pii > a (n);
	for (int i = 0; i < n; i++) {
		cin >> x >> l;
		a[i].first = (long) x - l;
		a[i].second = (long) x + l;
	}
	sort (a.begin(), a.end(), [&] (const pii & p1, const pii & p2) {
		if (p1.second == p2.second) {
			return p1.first < p2.first;
		}
		return p1.second < p2.second;
	});
	int cnt = 0;
	pii current = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i].first >= current.second) {
			current = a[i];
		} else {
			cnt++;
		}
	}
	cout << (n - cnt) << endl;
	return 0;
}

