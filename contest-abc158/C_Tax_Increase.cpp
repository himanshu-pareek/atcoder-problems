#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

// Problem link : https://atcoder.jp/contests/abc158/tasks/abc158_c

int main() {
	int A, B;
	cin >> A >> B;
	int low = 0, high = 10000;
	int answer = -1;
	for (int i = 0; i <= 10000; i++) {
		int P1 = 0.08 * i;
		int P2 = 0.10 * i;
		if (P1 == A && P2 == B) {
			answer = i;
			break;
		}
	}
	//while (low <= high) {
		//int mid = low + (high - low) / 2;
		//int P1 = 0.08 * mid;
		//int P2 = 0.10 * mid;
		//if (P1 == A && P2 == B) {
			//answer = mid;
			//high = mid - 1;
		//} else if (P1 < A) {
			//low = mid + 1;
		//} else {
			//high = mid - 1;
		//}
	//}
	cout << answer << endl;
	return 0;
}
