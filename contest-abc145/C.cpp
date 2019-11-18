#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int > ;

// template < typename T >
// void (const vector < T > & )

void solve () {

}

double dist (pii a, pii b) {
    ll dist_sqr = (a.first - b.first) * (a.first - b.first)
                     + (a.second - b.second) * (a.second - b.second);
    return sqrt (dist_sqr);
}

int main() {
    int n;
    cin >> n;
    vector < pii > a (n);
    for (pii & x : a) scanf ("%d %d", & (x.first), & (x.second));
    double totalDistance = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            totalDistance += dist (a[i], a[j]);
        }
    }
    printf ("%.6lf\n", totalDistance / n);
    return 0;
}
