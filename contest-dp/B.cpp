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

int main() {
	int N, k;
	scanf ("%d %d", &N, &k);
	vector < int > h (N);
	for (int & x : h) {
		scanf ("%d", &x);
	}
	vector < int > dp (N, INF);
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j <= i + k; j++) {
			if (j < N){
				dp[j] = min (dp[j], dp[i] + abs (h[i] - h[j]));
			}
		}
	}
	// printVector (h);
	// printVector (dp);
	printf ("%d\n", dp[N - 1]);
	return 0;
}
