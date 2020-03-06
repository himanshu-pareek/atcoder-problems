//#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, ans = 0, minElement = INT_MAX, p;
	cin >> n;
	while (n--) {
		cin >> p;
		if (p <= minElement) {
			ans++;
		}
		minElement = min (minElement, p);
	}
	cout << ans << endl; 
	return 0;
}
