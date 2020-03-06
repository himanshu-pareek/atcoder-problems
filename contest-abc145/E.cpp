#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;
#define A first
#define B second

void max_self (int & a, int b) {
	if (a < b) a = b;
}

int main() {
    int n, t;
    cin >> n >> t;
    vector < pii > dishes (n);
    for (pii & x : dishes) scanf ("%d %d", & (x.A), & (x.B));
    vector < vector < int > > dp (n + 1, vector < int > (t + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= t; w++) {
            int not_taken = dp[i - 1][w];
            int taken = (w >= dishes[i - 1].A) ? (dp[i - 1][w - dishes[i - 1].A] + dishes[i - 1].B) : 0;
            dp[i][w] = max (not_taken, taken);
        }
    }
    vector < vector < int > > dp2 (n + 1, vector < int > (t + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
		for (int w = 0; w <= t; w++) {
			int not_taken = dp2[i + 1][w];
			int taken = (w >= dishes[i].A) ? (dp2[i + 1][w - dishes[i].A] + dishes[i].B) : 0;
			dp2[i][w] = max (not_taken, taken);
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < t; j++) {
			max_self (answer, dp[i][j] + dp2[i + 1][t - 1 - j] + dishes[i].B);
		}
	}
    //vector < bool > taken (n, false);
    //f (dp, taken, n, t, dishes);
    //int totalWeight = 0, maxHappiness = 0;
    //int minHappiness = INT_MAX;
    //int countTaken = 0;
    //for (int i = 0; i < n; i++) {
        //if (taken[i]) {
            //totalWeight += dishes[i].A;
            //minHappiness = min (minHappiness, dishes[i].B);
            //countTaken = 0;
        //} else {
            //maxHappiness = max (maxHappiness, dishes[i].B);
        //}
    //}
    //// cout << totalWeight << " " << minHappiness << " " << maxHappiness << " " << dp[n][t] << endl;
    //int answer = dp[n][t];
    //if (totalWeight < t) {
        //answer = dp[n][t] + maxHappiness;
    //} else if (maxHappiness > minHappiness) {
        //answer = dp[n][t] + maxHappiness - minHappiness;
    //}
    cout << answer << endl;
    return 0;
}
