#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int c = max (a, b);
	int d = min (a, b);
	for (int i = 0; i < c; i++) {
		cout << d;
	}
	cout << endl;
	return 0;
}
