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

const ll INF = 1e18L + 5;

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
	vector < int > weight (N), value (N);
	for (int i = 0; i < N; i++) {
		scanf ("%d %d", &weight[i], &value[i]);
	}
	int value_sum = 0;
	for (int x : value) {
		value_sum += x;
	}
	vector < ll > dp (value_sum + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int value_already = value_sum - value[i]; value_already >= 0; value_already--) {
			min_self (dp[value_already + value[i]], dp[value_already] + weight[i]);
		}
	}
	int answer = 0;
	for (int i = 1; i <= value_sum; i++) {
		if (dp[i] <= W) answer = i;
	}
	printf ("%d\n", answer);
	return 0;
}

