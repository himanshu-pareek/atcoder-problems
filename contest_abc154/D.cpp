#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int N, K;
	scanf ("%d %d", &N, &K);
	vector < int > P (N);
	for (int & x : P) scanf ("%d", &x);
	ll maxSum = 0LL, sum = 0LL;
	for (int i = 0; i < K; i++) {
		sum += P[i];
	}
	maxSum = sum;
	for (int i = K; i < N; i++) {
		sum -= P[i - K];
		sum += P[i];
		maxSum = max (maxSum, sum);
	}
	double answer = (double) (maxSum + K) / 2.0;
	printf ("%.9lf\n", answer);
	return 0;
}
