#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, k; cin >> n >> k;
	ll x; cin >> x;
	string s; cin >> s;
	vector<ll> dp; dp.push_back(1);
	vector<ll> ans; x--;

	int sz = 0;
	for (int i = n-1; i >= 0; i--) {
		if (s[i] != '*') continue;
		sz = 0;
		while (i >= 0 and s[i] == '*')
			i--, sz++;
		if ((__int128_t) dp.back() * (sz*k + 1) > x) {
			// At this point we can do anything
			break;
		} else {
			dp.push_back(dp.back() * (sz*k + 1));
		}
	}

	reverse(dp.begin(), dp.end());
	for (ll &i: dp) {
		ans.push_back(x / i);
		x %= i;
	}

	string ansRev = "";
	for (int i = n-1; i >= 0;) {
		if (s[i] == 'a') {
			ansRev += s[i--];
		} else {
			if (ans.empty()) continue;
			ll numBs = ans.back(); ans.pop_back();
			ansRev += string(numBs, 'b');
			while (i >= 0 and s[i] == '*') i--;
		}
	}

	reverse(ansRev.begin(), ansRev.end());
	cout << ansRev;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
