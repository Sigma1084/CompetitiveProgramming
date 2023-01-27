#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	ll n, y; cin >> n >> y;
	vector<ll> a(n); for (auto &x: a) cin >> x;

	ll x = 0, bit = 1;
	
	while (1) {
		bool br = true, add = true;
		for (ll &i: a) {
			if (i) br = false;
			if (i & 1) add = false;
			i /= 2;
		}

		if (br) {
			x += y * bit;
			break;
		}

		if ((y & 1) == 0 and !add) {
			cout << -1;
			return;
		}

		if (add and (y&1)) x += bit;
		bit *= 2;
		y /= 2;
	}

	cout << x;
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
