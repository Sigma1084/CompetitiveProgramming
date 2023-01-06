#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<ll> a(n); for (auto &x: a) cin >> x;

	sort(a.begin() + 1, a.end());
    for (int i = 1; i < n; i++) {
        if (a[i] < a[0]) continue;
        // a[i] > a[0]
        a[0] = (a[0] + a[i] + 1) / 2;
    }

    cout << a[0];
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

