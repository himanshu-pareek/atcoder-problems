#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve() {
	
}

int main() {
	ios::sync_with_stdio (false);
	int n;
	string s;
	cin >> n;
	map < string, int > mp;
	vector < int > duration (n);
	for (int i = 0; i < n; i++) {
		cin >> s >> duration[i];
		mp[s] = i;
	}
	cin >> s;
	int index = mp[s];
	int ans = 0;
	for (int i = index + 1; i < n; i++) {
		ans += duration[i];
	}
	cout << ans << endl;
	return 0;
}

