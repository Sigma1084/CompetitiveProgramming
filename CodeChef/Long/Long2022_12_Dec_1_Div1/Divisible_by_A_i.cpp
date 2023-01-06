#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;
    int g = a[0];
    for (auto &i: a) g = __gcd(i, g);
    for (auto &i: a) cout << i / g << ' ';
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

