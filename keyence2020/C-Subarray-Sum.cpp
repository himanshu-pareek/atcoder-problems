#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 1e9;

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
	int n, k, s;
	ios_base::sync_with_stdio (false);
	cin >> n >> k >> s;
	for (int i = 0; i < k; i++) {
		cout << s << " ";
	}
	int rest = (s == inf) ? 1 : inf;
	for (int i = k; i < n; i++) {
		cout << rest << " ";
	}
	cout << endl;
	return 0;
}

