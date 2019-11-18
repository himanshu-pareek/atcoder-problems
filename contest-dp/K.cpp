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

template < typename T >
void printMatrix (const vector < vector < T > > & mat) {
	for (const vector < T > vec : mat) {
		printVector (vec);
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

void add_self (int & a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int main() {
	int n, k;
	scanf ("%d %d", &n, &k);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", &x);
	vector < bool > dp (k + 1, false);
	// dp[i] = true => player 1 wins if there are i stones in the pile
	// else player 2 wins
	// Initially we can't take any stone, so player two wins
	for (int stones = 0; stones <= k; stones++){
		for (int x : a) {
			if (stones >= x && !dp[stones - x]) {
				dp[stones] = true;
			}
		}
	}

	puts (dp[k] ? "First" : "Second");
	return 0;
}

