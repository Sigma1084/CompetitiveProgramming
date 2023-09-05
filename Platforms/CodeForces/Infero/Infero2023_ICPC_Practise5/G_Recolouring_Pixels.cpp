#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	string s; cin >> s;

	/**
	 * 6: RGB RBG BRG BGR GRB GBR
	 */

	int ans = n;
	string ansStr = "";

	vector<string> choices = {"RGB", "RBG", "GBR", "GRB", "BRG", "BGR"};
	for (string c: choices) {
		int cur = 0;
		string t = s;
		for (int i = 0; i < n; i++) {
			if (s[i] != c[i % 3]) {
				cur += 1;
				t[i] = c[i % 3];
			}
		}
		if (cur < ans) {
			ans = cur;
			ansStr = t;
		}
	}

	cout << ans << '\n' << ansStr << endl;

	return 0;
}
