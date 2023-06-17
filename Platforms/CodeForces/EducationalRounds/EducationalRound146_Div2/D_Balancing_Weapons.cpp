#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, k; cin >> n >> k;
	vector<int> f(n), d(n);
	for (int &i: f) cin >> i;
	for (int &i: d) cin >> i;

	vector<pair<ll, int>> p(n);  // (p, f)
	for (int i = 0; i < n; i++) {
		p[i].first = 1LL * f[i] * d[i];
		p[i].second = f[i];
	}
	sort(p.begin(), p.end());

	int ans = n, cur;
	bool ok;
	for (int i = 0; i < n; i++) {
		// We assume the i-th to be the minimum p_i
		ok = true; cur = 0;
		for (int j = 0; j < n; j++) {
			cur += 1;
			if (p[j].first < p[i].first) {
				// We need to increase it by adding f[j]s
				// to mak it at least p_i
				ll diff = p[i].first - p[j].first;
				if (p[j].first + p[j].second * (ll)ceil(1.0 * diff / p[j].second) > p[i].first + k) {
					cerr << 4 << ' ';
					ok = false;
					break;
				}
			} else if (p[j].first > p[i].first + k) {
				// We need to decrease it by subtracting f[i]s
				// to make it slightly less than p_i
				ll diff = p[j].first - p[i].first - k;  // Need to decrease by at least diff
				if (p[j].first - p[j].second * (ll)ceil(1.0 * diff / p[j].second) < p[i].first) {
					ok = false;
					cerr << 3 << ' ';
					break;
				}
			} else {
				// No need to do anything
				cur -= 1;
			}
		}
		if (ok) {
			cerr << 2 << ' ';
			ans = min(ans, cur);
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
