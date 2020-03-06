#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int mul (int a, int b) {
	return (int) (((ll) a * b) % mod);
}

int power (int a, int k) {
	int ans = 1;
	while (k >= 1) {
		if (k & 1) ans = mul (ans, a);
		a = mul (a, a);
		k >>= 1;
	}
	return ans;
}

int inverse (int a) {
	return power (a, mod - 2);
}

void max_self (int & a, int b) {
	if (a < b) a = b;
}

vector < pair < int, int > > toAdd = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
	int h, w;
	cin >> h >> w;
	vector < string > maze (h);
	for (int i = 0; i < h; i++) {
		cin >> maze[i];
	}
	int ans = 0;
	auto isValid = [&] (int x, int y) {
		return x >= 0 && y >= 0 && x < h && y < w && maze[x][y] == '.';
	};
	for (int starti = 0; starti < h; starti++) {
		for (int startj = 0; startj < w; startj++) {
			if (maze[starti][startj] == '#') continue;
			queue < pair < int, int > > q;
			vector < vector < bool > > visited (h, vector < bool > (w));
			vector < vector < int > > d (h, vector < int > (w));
			d[starti][startj] = 0;
			visited[starti][startj] = true;
			q.push (make_pair (starti, startj));
			while (!q.empty()) {
				pair < int, int > u = q.front(); q.pop();
				max_self (ans, d[u.first][u.second]);
				for (pair < int, int > p : toAdd) {
					int x = u.first + p.first;
					int y = u.second + p.second;
					if (isValid (x, y) && !visited[x][y]) {
						d[x][y] = d[u.first][u.second] + 1;
						visited[x][y] = true;
						q.push (make_pair (x, y));
					}
				}
			}
		}
	}
	cout << ans << endl;			
	return 0;
}

