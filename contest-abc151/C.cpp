#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
	int n, m, p;
	string s;
	cin >> n >> m;
	vector < int > penalties (n), ac (n);
	while (m--) {
		cin >> p >> s;
		p--;
		if (s == "AC") {
			ac[p] = 1;
		} else {
			if (ac[p] == 0) {
				penalties[p]++;
			}
		}
	}
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++) {
		sum1 += ac[i] * penalties[i];
		sum2 += ac[i];
	}
	cout << sum2 << " " << sum1 << endl;
	return 0;
}

