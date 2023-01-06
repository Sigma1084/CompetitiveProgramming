#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

    if (accumulate(a.begin(), a.end(), 0) % 2 == 0) {
        cout << 0;
        return;
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int bef = a[i];
        int aft = a[i] / 2;
        int req = 1;
        while (bef % 2 == aft % 2) {
            bef = aft;
            aft /= 2;
            req++;
        }
        ans = min(ans, req);
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

