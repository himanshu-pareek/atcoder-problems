/**
 * Contest : AtCoder Beginner Contest 159
 * Contest URL : https://atcoder.jp/contests/abc159/
 * Problem : E - Dividing Chocolate
 * Problem URL : https://atcoder.jp/contests/abc159/tasks/abc159_e
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int inf = 1000000;

int main() {
	int h, w, k;
	cin >> h >> w >> k;
	vector < string > bar (h);
	for (int i = 0; i < h; i++) {
		cin >> bar[i];
	}
	int answer = INT_MAX;
	//vector < bool > cut (h - 1);
	for (int state = 0; state < (1 << (h - 1)); state++) {
		vector < int > cuts;
		for (int i = 0; i < h - 1; i++) {
			if ((state >> i) & 1) {
				cuts.push_back (i);
			}
		}
		cuts.push_back (h - 1);
		vector < vector < int > > white_bars (cuts.size(), vector < int > (w));
		int start = 0;
		int index = 0;
		for (int end : cuts) {
			for (int j = 0; j < w; j++) {
				int s = 0;
				for (int i = start; i <= end; i++) {
					s += (bar[i][j] == '1');
				}
				white_bars[index][j] = s;
			}
			index++;
			start = end + 1;
		}
		vector < int > sums (white_bars.size());
		int count = 0;
		for (int j = 0; j < w; j++) {
			bool valid = true;
			for (int i = 0; i < sums.size(); i++) {
				sums[i] += white_bars[i][j];
				if (sums[i] > k) { valid = false; break; }
			}
			if (!valid) {
				count++;
				//sums.assign (sums.size(), 0);
				for (int i = 0; i < sums.size(); i++) {
					sums[i] = white_bars[i][j];
					if (sums[i] > k) {
						count = inf;
						break;
					}
				}
			}
		}
		answer = min (answer, count + (int) cuts.size() - 1);
	}
	cout << answer << endl;
	return 0;
}
