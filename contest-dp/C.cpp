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
	int n;
	scanf ("%d", &n);
	vector < int > dp (3);
	vector < int > h (3);
	while (n--) {
		for (int & x : h) scanf ("%d", &x);
		vector < int > new_dp (3);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i != j){
					new_dp[i] = max (new_dp[i], dp[j] + h[i]);
				}
			}
		}
		dp = new_dp;
	}
	printf ("%d\n", max ({dp[0], dp[1], dp[2]}));
	return 0;
}

