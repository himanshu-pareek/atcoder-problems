#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf ("%d", &N);
	vector < int > A (N);
	for (int & x : A) scanf ("%d", &x);
	unordered_set < int > m;
	bool distinct = true;
	for (int x : A) {
		if (m.find (x) != m.end()) {
			distinct = false;
			break;
		}
		m.insert (x);
	}
	if (distinct) {
		printf ("YES\n");
	} else {
		printf ("NO\n");
	}
	return 0;
}
