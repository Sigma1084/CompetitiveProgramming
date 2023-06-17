#include <bits/stdc++.h>
using ll = int64_t;
using std::vector;
#define all(x) (x).begin(), (x).end()


std::ifstream _cin("hps.in");
std::ofstream _cout("hps.out");


void solve() {
	int n, K; _cin >> n >> K;
	vector<int> a(n + 1);

	for (int i = 1; i <= n; i++) {
		char c; _cin >> c;
		switch(c) {
			case 'H': a[i] = 0; break;
			case 'P': a[i] = 1; break;
			case 'S': a[i] = 2;
		}
	}

	// 1 > 0, 2 > 1 and 0/3 > 2

	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(K + 2, vector<int>(3)));

	for (int i = 1, profit; i <= n; i++) {
		for (int k = 1; k <= K + 1; k++) {
			for (int s = 0; s < 3; s++) {
				profit = (s == 0) ? (a[i] == 2) : (s == a[i] + 1);
				dp[i][k][s] = std::max({
					dp[i-1][k][s] + profit,
					dp[i-1][k-1][(s+1) % 3] + profit,
					dp[i-1][k-1][(s+2) % 3] + profit
				});
			}
		}
	}

	_cout << *max_element(all(dp[n][K+1]));
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); _cout << '\n';
	}
	return 0;
}
