#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int fact (int n) {
	if (n == 0) return 1;
	return n * fact (n - 1);
}

int count_rank (string s, int n) {
	vector < bool > present (n + 1, true);
	auto count_smaller = [&] (int x) {
		int cnt = 0;
		for (int i = 1; i < x; i++) {
			cnt += present[i];
		}
		return cnt;
	};
	int rnk = 0;
	//cout << "s = " << s << endl;
	for (int i = 0; i < n; i++) {
		int smaller = count_smaller (s[i] - '0');
		//cout << "smaller = " << smaller << endl;
		int x = smaller * fact (n - 1 - i);
		//cout << "x = " << x << endl;
		rnk += x;
		present[s[i] - '0'] = false;
	}
	//cout << s << " => " << rnk << endl;
	return rnk;
}

int solve() {
	int n;
	string p, q;
	char c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		p += c;
	}
	for (int i = 0; i < n; i++) {
		cin >> c;
		q += c;
	}
	//cout << p << endl << q << endl;
	if (p < q) {
		return count_rank (q, n) - count_rank (p, n);
	} else {
		return count_rank (p, n) - count_rank (q, n);
	}
}

int main() {
	ios::sync_with_stdio (false);
	int ans = solve();
	cout << ans << endl;
	return 0;
}

