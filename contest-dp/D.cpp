#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1e9 + 7

template < typename T >
void printVector (const vector < T > & vec) {
	for (const T x : vec) {
		cout << x << " ";
	}
	cout << endl;
}

const int INF = 1e9 + 5;

template < typename T >
void min_self (T& a, T b) {
	a = min (a, b);
}

template < typename T >
void max_self (T& a, T b) {
	a = max (a, b);
}

int main() {
	int N, W, w, v;
	scanf ("%d %d", &N, &W);
	vector < ll > dp (W + 1);	// 0 ... W
	// dp[i] - the maximum total value of item
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		scanf ("%d %d", &w, &v);
		for (int weight = W - w; weight >= 0; weight--) {
			max_self (dp[weight + w], dp[weight] + v);
		}
	}
	ll answer = 0;
	for (int i = 0; i <= W; i++) {
		max_self (answer, dp[i]);
	}
	printf ("%lld\n", answer);
	return 0;
}

