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

void print (vector < vector < int > > & dp, string & s, string & t, int i, int j) {
	if (i == 0 || j == 0) return;
	if (dp[i][j] == dp[i - 1][j - 1] + 1)  {
		print (dp, s, t, i - 1, j - 1);
		printf ("%c", s[i - 1]);
	} else if (dp[i][j] == dp[i - 1][j]) {
		print (dp, s, t, i - 1, j);
	} else {
		print (dp, s, t, i, j - 1);
	}
}

int main() {
	string s, t;
	// scanf ("%s %s", s, t);
	cin >> s >> t;
	int m = s.size(), n = t.size();
	vector < vector < int > > dp (m + 1, vector < int > (n + 1, 0));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max (dp[i][j - 1], dp[i - 1][j]);
		}
	}
	int i = m, j = n;
	string temp = "";
	while (i > 0 && j > 0) {
		if (dp[i][j] == dp[i - 1][j - 1] + 1)  {
			temp += s[i - 1];
			i--; j--;
		} else if (dp[i][j] == dp[i - 1][j]) {
			i--;
		} else {
			j--;
		}
	}
	// print (dp, s, t, m, n);
	reverse (temp.begin(), temp.end());
	cout << temp << endl;
	return 0;
}

