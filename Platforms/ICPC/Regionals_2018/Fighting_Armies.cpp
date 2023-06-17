#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

template<typename T, typename U> ostream &operator << (ostream &ost, const pair<T, U> &p) {
    ost << "("; ost << p.first << " " << p.second; ost << ")"; return ost; }
template<typename T> ostream &operator << (ostream &ost, const vector<T> &v) {
    ost << "["; for(const auto &x: v) ost << ' ' << x; ost << " ]"; return ost; }

void solve() {
	int N; cin >> N;
	vector<ll> a(N);
	for (auto &i: a) cin >> i;
	ll l, r; cin >> l >> r;

	ll x = 1, g;
	for (ll i: a) {
		g = gcd(i, x);
		i /= g;
		// Need to multiply i to x
		if (log10(i) + log10(x) > 18) {
			x = 1e18 + 1;
		} else {
			x *= i;
		}
	}

	ll R = r / x, L = ceil(l / x);

	ll tot = r - l + 1;
	ll pres = R - L + 1;

	cout << tot - pres;
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
