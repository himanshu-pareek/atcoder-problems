#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// template < typename T >
// void (const vector < T > & )

void solve () {

}

const int mod = 1e9 + 7;

int mul (int a, int b) {
    return ((ll) a * b) % mod;
}

int power (int a, int n) {
    int answer = 1;
    while (n >= 1) {
        if (n % 2) {
            answer = mul (answer, a);
        }
        a = mul (a, a);
        n >>= 1;
    }
    return answer;
}

int inverse (int a) {
    return power (a, mod - 2);
}

int fact (int n) {
    int answer = 1;
    for (int i = 1; i <= n; i++) {
        answer = mul (answer, i);
    }
    return answer;
}

int main() {
    int x, y;
    cin >> x >> y;
    int a = 2 * y - x;
    int b = 2 * x - y;
    if (a<0 || b < 0 || (a%3) || (b%3)) {
        cout << 0 << endl;
        return 0;
    }
    int p = a / 3, q = b / 3;
    int upper = fact (p + q);
    int lower = mul (fact (p), fact (q));
    int answer = mul (upper, inverse (lower));
    cout << answer << endl;
    return 0;
}
