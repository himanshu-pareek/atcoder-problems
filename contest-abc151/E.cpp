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

int main() {
	ios::sync_with_stdio (false);
	int n, k;
	cin >> n >> k;
	vector < int > a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort (a.begin(), a.end());
    vector < int > fact (n + 1), invfact (n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mul (fact[i - 1], i);
    }
    for (int i = 0; i <= n; i++) {
        invfact[i] = inverse (fact[i]);
    }
    auto choose = [&] (int N, int K) {
        if (N < K) return 0;
        return mul (fact[N], mul (invfact[K], invfact[N - K]));
    };
    int answer = 0;
    int nck = choose (n, k);
    for (int i = 0; i + 1 < n; i++) {
        int diff = (a[i + 1] - a[i]) % mod;
        // diff * (nck - ((i + 1)ck + (n - 1 - i)ck)) 
        int res = nck;
        sub_self (res, choose (i + 1, k));
        sub_self (res, choose (n - 1 - i, k));
        add_self (answer, mul (res, diff));
    }
    printf ("%d\n", answer);
	return 0;
}

