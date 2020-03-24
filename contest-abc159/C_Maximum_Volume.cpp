#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int main() {
	int L;
	cin >> L;
	double a = (double) L / 3.0;
	double answer = a * a * a;
	//double answer = pow ((double) L, 1.0 / 3.0);
	printf ("%.7lf\n", answer);
	return 0;
}
