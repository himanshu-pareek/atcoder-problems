#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

bool isPal (string s) {
	string t = s;
	reverse (t.begin(), t.end());
	return s == t;
}

int main() {
	string s;
	cin >> s;
	bool flag1 = isPal (s);
	string t = s.substr (0, s.length() / 2);
	bool flag2 = isPal (t);
	t = s.substr (s.length() / 2 + 1);
	bool flag3 = isPal (t);
	if (flag1 && flag2 && flag3) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
