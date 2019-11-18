#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
    int n;
    scanf ("%d", &n);
    map < string, int > index;
    vector < priority_queue < pair < int, int > >> maxp;
    vector < priority_queue < pair < int, int >, vector < pair < int, int > > , greater < pair < int, int > > > > minp;
    string name, operation;
    int quantity, price;
    int currentIndex = 0;
    for (int i = 0; i < n; i++) {
        cin >> name >> operation;
        scanf ("%d %d", &quantity, &price);
        if (index.find (name) == index.end()) {
            index[name] = currentIndex;
            priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > p;
            priority_queue < pair < int, int > > q;
            minp.push_back (p);
            maxp.push_back (q);
            currentIndex++;
        }
        int ind = index[name];
        if (operation == "SELL") {
            minp[ind].push ({price, quantity});
        } else {
            maxp[ind].push ({price, quantity});
        }
    }

    int total = 0;

    for (int i = 0; i < minp.size(); i++) {
        while (!minp[i].empty() && !maxp[i].empty()) {
            pair < int, int > s = minp[i].top(); minp[i].pop();
            pair < int, int > b = maxp[i].top(); maxp[i].pop();
            if (s.first > b.first) {
                break;
            }
            int q = min (s.second, b.second);
            s.second -= q;
            b.second -= q;
            if (s.second > 0) {
                minp[i].push (s);
            }
            if (b.second > 0) {
                maxp[i].push (b);
            }
        }
        // cout << "i = " << i << endl;
        while (!minp[i].empty()) {
            pair < int, int > s = minp[i].top(); minp[i].pop();
            total += s.second;
            // cout << s.second << " " << s.first << endl;
        }
        while (!maxp[i].empty()) {
            pair < int, int > b = maxp[i].top(); maxp[i].pop();
            total += b.second;
            // cout << b.second << " " << b.first << endl;
        }
    }

    cout << total << endl;
    return 0;
}
