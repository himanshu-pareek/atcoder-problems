/**
 * Question Link: https://atcoder.jp/contests/dp/tasks/dp_w
 * Video solution: https://www.youtube.com/watch?v=FAQxdm0bTaw
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

void add_self (int & a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

void sub_self (int & a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
}

int main() {

	return 0;
}
