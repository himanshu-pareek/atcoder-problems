#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

// Problem link : https://atcoder.jp/contests/abc158/tasks/abc158_d

int main() {
	string s; int q;
	cin >> s >> q;
	int t, f; char c;
	deque < char > dq;
	bool reversed = false;
	for (char c : s) {
		dq.push_back (c);
	}
	while (q--) {
		cin >> t;
		if (t == 1) {
			reversed = !reversed;
		} else {
			cin >> f >> c;
			bool rev = reversed ^ (f == 2);
			if (rev) {
				dq.push_back (c);
			} else {
				dq.push_front (c);
			}
		}
	}
	s = "";
	if (reversed) {
		while (!dq.empty()) {
			s += dq.back(); dq.pop_back();
		}
	} else {
		while (!dq.empty()) {
			s += dq.front(); dq.pop_front();
		}
	}
	cout << s << endl;
	return 0;
}
