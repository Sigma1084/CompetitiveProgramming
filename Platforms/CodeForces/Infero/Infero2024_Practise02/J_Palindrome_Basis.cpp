#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

constexpr int P = 1'000'000'007;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	constexpr int N = 40000;

	vector<int> palindromes;
	for (int i = 2; i <= N; i++) {
		int rev = 0;
		for (int n = i; n; n /= 10)
			rev = rev * 10 + n % 10;
		if (i == rev) palindromes.push_back(i);
	}
	// There are 498, which is < 500 palindromes

	vector<int> dp(N + 1, 1);

	for (int p: palindromes) {
		for (int n = p; n <= N; n++) {
			(dp[n] += dp[n - p]) %= P;
		}
	}

	int t; cin >> t;
	for (int i = 0, n; i < t; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}
