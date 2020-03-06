#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
			ans++;
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio (false);
	int t;
	t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

