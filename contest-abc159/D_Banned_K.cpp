#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int main() {
	int n;
	cin >> n;
	vector < int > a (n);
	for (int & x : a) {
		scanf ("%d", &x);
	}
	vector < int > counts (n + 1);
	for (int x : a) {
		counts[x]++;
	}
	ll sum = 0LL;
	for (int count : counts) {
		sum += (ll) count * (count - 1) / 2;
	}
	for (int i = 0; i < n; i++) {
		cout << (sum - ((ll) counts[a[i]] - 1)) << endl;
	}
	return 0;
}
