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

void max_self (int & a, int b) {
	if (a < b) a = b;
}

const int mx = 1e6 + 5;

int main() {
	int N;
	scanf ("%d", &N);
	vector < int > A (N);
	for (int & x : A) scanf ("%d", &x);
	vector < int > answer (mx);
	for (int x : A) {
		map < int, int > m;
		for (int i = 2; i * i <= x; i++) {
			while (x % i == 0) {
				m[i]++;
				x /= i;
			}
		}
		if (x != 1) {
			m[x]++;
		}
		for (auto it = m.begin(); it != m.end(); it++) {
			max_self (answer[it -> first], it -> second);
		}
	}
	int lcm = 1;
	for (int i = 2; i < mx; i++) {
		lcm = mul (lcm, pow (i, answer[i]));
	}
	int ans = 0;
	for (int x : A) {
		add_self (ans, mul (lcm, inverse (x)));
	}
	printf ("%d\n", ans);
	return 0;
}

