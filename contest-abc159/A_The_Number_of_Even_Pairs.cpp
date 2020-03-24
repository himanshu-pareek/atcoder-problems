#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int main() {
	int n, m;
	cin >> n >> m;
	ll answer = n * (n - 1) / 2;
	answer += m * (m - 1) / 2;
	cout << answer << endl;
	return 0;
}
