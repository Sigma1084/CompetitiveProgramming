#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

map<ll, int> dp;

ll dpp(ll n) {
	if (dp.find(n) != dp.end())
		return dp[n];
	if (n % 2 == 1)
		return dp[n] = dpp(n/2) + dpp(n/2);
	else
		return dp[n] = 1 + dpp(n/2) + dpp(n/2 - 1);
}

void solve() {
	ll n; cin >> n;
	dp.clear();
	dp[0] = 0; dp[1] = 0;
	cout << (1LL << dpp(n));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	dp[0] = 0; dp[1] = 0;

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}

	return 0;
}

