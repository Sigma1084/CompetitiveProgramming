#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


ll maintainNonNeg(const vector<ll> &arr, ll cur) {
	priority_queue<ll> pq;
	ll ans = 0;
	for (auto &i: arr) {
		if (i >= 0) {
			cur += i;
		} else {
			cur += i;
			pq.push(-2*i);
			while (cur < 0) {
				cur += pq.top();
				pq.pop();
				ans++;
			}
		}
	}
	return ans;
}


void solve() {
	ll n, m; cin >> n >> m;
	vector<ll> a(n); for (auto &x: a) cin >> x;

	ll ans = ((m > 1) and (a[m-1] > 0));
	vector<ll> b; for (int i = m-2; i >= 1; i--) b.push_back(-a[i]);
	ans += maintainNonNeg(b, abs(a[m-1]));
	vector<ll> c; for (int i = m; i < n; i++) c.push_back(a[i]);
	ans += maintainNonNeg(c, 0);
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