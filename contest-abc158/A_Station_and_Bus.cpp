#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

// Problem link : https://atcoder.jp/contests/abc158/tasks/abc158_a

int main() {
	string s;
	cin >> s;
	bool isA = false, isB = false;
	for (char c : s) {
		if (c == 'A') isA = true;
		else if (c == 'B') isB = true;
	}
	if (isA && isB) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
