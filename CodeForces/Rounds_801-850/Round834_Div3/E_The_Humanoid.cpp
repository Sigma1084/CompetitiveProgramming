#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

int n;
vector<int> a;

ll doIt(int i, ll h, int d, int t) {
    // cout << "Executing " << i << ' ' << h << ' ' << d << ' ' << t << '\n';
    if (i == n) {
        return i;
    }
    for (; i < n and a[i] < h; i++) {
        h += a[i] / 2;
    }
    return max(d?doIt(i, 2*h, d-1, t):i, t?doIt(i, 3*h, d, t-1):i);
}

void solve() {
    cin >> n;
    ll h; cin >> h;
    a.clear(); a.resize(n);
    for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    cout << doIt(0, h, 2, 1);
    // cout << h;
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

