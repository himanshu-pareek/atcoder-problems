#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// template < typename T >
// void (const vector < T > & )

void solve () {

}

int main() {
    int n; string s;
    cin >> n >> s;
    if (n%2) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0, j = n/2; i < n/2; i++, j++) {
        if (s[i] != s[j]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
