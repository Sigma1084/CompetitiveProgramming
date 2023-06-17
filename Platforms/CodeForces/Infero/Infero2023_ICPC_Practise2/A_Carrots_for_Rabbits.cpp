#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n); for (auto &x: a) cin >> x;

	/**
	 * f(l, p) is the sum of time taken to eat carrots when
	 * a carrot of length l is cut into p pieces
	 */
	function<ll(int, int)> f = [&] (int l, int p) -> ll {
		int w = l / p, p2 = l % p;
		return 1LL * (p - p2) * w * w + 1LL * p2 * (w + 1) * (w + 1);
	};

	ll ans = 0;

	priority_queue<tuple<ll, int, int>> pq;  // gain, l, p
	for (const int &l: a) {
		pq.push( { f(l, 1) - f(l, 2), l, 1 } );
		ans += f(l, 1);
	}

	while (k-- > n) {
		auto [gain, l, p] = pq.top(); pq.pop();
		ans -= gain;
		pq.push( { f(l, p+1) - f(l, p+2), l, p+1 } );
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	solve();
	cout << endl;

	return 0;
}
