#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

void sub_self (int & a, int b) {
	a -= b;
	if (a < 0) a += mod;
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

int choose (int n, int r) {
	int ans = 1;
	int k = 1;
	while (k <= r) {
		ans = mul (ans, mul (n, inverse (k)));
		n--; k++;
	}
	return ans;
}

int f (int r, int c) {
	add_self (r, c);
	add_self (r, 2);
	add_self (c, 1);
	return choose (r, c);
}

int main() {
	int r1, r2, c1, c2;
	//cout << choose (1, 1) << " " << choose (1, 2) << " " << choose (10, 3) << endl;
	scanf ("%d %d %d %d", &r1, &c1, &r2, &c2);
	int a = f (r2, c2);
	int b = f (r2, c1 - 1);
	int c = f (r1 - 1, c2);
	int d = f (r1 - 1, c1 - 1);
	//cout << a << " " << b << " " << c << " " << d << endl;
	int ans = a;
	sub_self (ans, b);
	sub_self (ans, c);
	add_self (ans, d);
	cout << ans << endl;
	return 0;
}

