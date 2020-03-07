#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

// Problem link : https://atcoder.jp/contests/abc158/tasks/abc158_b

int main() {
	ll N, A, B;
	cin >> N >> A >> B;
	ll div = N / (A + B);
	ll answer = div * A;
	N -= div * (A + B);
	answer += min (N, A);
	cout << answer << endl;
	return 0;
}
