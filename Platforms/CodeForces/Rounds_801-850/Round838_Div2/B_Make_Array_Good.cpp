#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;


void solve() {
	int n; cin >> n;
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }

    sort(a.begin(), a.end());

    cout << n << '\n';
    ll bef = a[0].first;
    for (auto &[num, pos]: a) {
        // We have number and a before.
        // We need to make number divisible by bef
        ll x = (bef - (num % bef)) % bef;
        cout << pos << ' ' << x << '\n';
        bef = num + x;
    }
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

