#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 998244353;

ll modPow(ll a, ll b) {
	ll ans = 1;
	for (; b; b /= 2, a = a*a % MOD)
		if (b % 2)
			ans = ans*a % MOD;
	return ans;
}

void solve() {
	string s; cin >> s;
	int k; cin >> k;

	if (k == 0) {
		cout << s.length();
		return;
	}

	/* Perform operation once to construct the array */
	reverse(s.begin(), s.end());
	vector<int> a;
	for (int i = 0, pos = 0; i < s.size(); i++)
		for (auto _ = '0'; _ < s[i]; _++)
			a.push_back(pos += i+1);
	int n = a.size(); k--;
	reverse(a.begin(), a.end());

	/* Computing the length after k operations */
	ll ans = 0, coEf = 1;
	for (int i = 0; i < n; i++) {
		ans += coEf * a[i];
		coEf *= (k+i) * modPow(i+1, MOD-2) % MOD;
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

