#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

std::array<int, 5> val = {1, 10, 100, 1000, 10000};

void solve() {
	string s; cin >> s;
	int n = s.size();

	char greatest = 'A';
	ll cur = 0, ans = 0;
	vector<ll> ansFrom(n + 1);
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] < greatest) cur -= val[s[i] - 'A'];
		else cur += val[s[i] - 'A'];
		greatest = max(greatest, s[i]);
		ansFrom[i] = cur;
	}

	cur = 0, ans = ansFrom[0];
	vector<ll> states(5, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			ans = max(ans, states[j] + val[j] + ansFrom[i + 1]);
			// cerr << i << ": " << char(j + 'A') << ' ' << states[j] << ' ' << ansFrom[i + 1] << '\n';
			if (s[i] < j + 'A') states[j] -= val[s[i] - 'A'];
			else states[j] += val[s[i] - 'A'];
		}
	}

	cout << ans;
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
