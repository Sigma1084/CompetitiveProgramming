#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

void solve() {
	int n; cin >> n;
	vector<ll> a(n); for (auto &x: a) cin >> x;

	sort(a.begin(), a.end());
	ll num = 1LL * a.front() * a.back();

	vector<ll> d;
	ll i;
	for (i = 2; i * i < num and d.size() < n + 1; i++) {
		if (num % i == 0) {
			d.push_back(i);
			d.push_back(num / i);
		}
	}
	if (i * i == num) {
		d.push_back(i);
	}

	sort(d.begin(), d.end());

	if (d == a) {
		cout << num;
	} else {
		cout << -1;
	}
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