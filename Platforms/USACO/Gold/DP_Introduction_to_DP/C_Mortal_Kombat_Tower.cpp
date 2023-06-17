#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

template<typename T, typename U> ostream &operator << (ostream &ost, const pair<T, U> &p) {
    ost << "("; ost << p.first << " " << p.second; ost << ")"; return ost; }
template<typename T> ostream &operator << (ostream &ost, const vector<T> &v) {
    ost << "["; for(const auto &x: v) ost << ' ' << x; ost << " ]"; return ost; }

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	if (n <= 1) {
		cout << a[0];
		return;
	}

	/**
	 * dp1[i] : Answer if you start at the i-th index
	 * dp2[i] : Answer if your friend starts at the i-th index
	 * Answer in the end will be dp2[0]
	 */
	vector<int> dp1(n, n), dp2(n, n);
	dp1[n-2] = dp1[n-1] = 0;  // You can finish anything off
	dp2[n-1] = a[n-1];  // He has to kill the last one himself
	dp2[n-2] = a[n-2];  // He has to kill the one and you will clear the next

	for (int i = n-3; i >= 0; i--) {
		dp1[i] = min(dp2[i+1], dp2[i+2]);  // You kill 1 or 2 depending upon him
		dp2[i] = a[i] + min(dp1[i+1], a[i+1] + dp1[i+2]);
	}

	cout << dp2[0];
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
