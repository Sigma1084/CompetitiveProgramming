#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false); 
	std::cin.tie(nullptr);

	int n; std::cin >> n;
	std::vector<int> a(n);
	for (int &x: a) std::cin >> x;

	// dp[i] = length of longest increasing subsequence ending at i
	std::map<int, int> dp;
	for (int i: a) {
		dp[i] = std::max(dp[i], dp[i-1] + 1);
		if (dp[i-1] == 0) dp.erase(i-1);
	}

	int maxLen = 0, x = 0;
	for (auto [_x, len]: dp) {
		if (len > maxLen) {
			maxLen = len;
			x = _x;
		}
	}

	std::vector<int> path;
	for (int i = 0, e = x - maxLen + 1; i < n and e <= x; i++) {
		if (a[i] == e) {
			path.push_back(i);
			e++;
		}
	}

	std::cout << maxLen << '\n';
	for (int i: path) std::cout << i + 1 << ' ';

	return 0;
}
