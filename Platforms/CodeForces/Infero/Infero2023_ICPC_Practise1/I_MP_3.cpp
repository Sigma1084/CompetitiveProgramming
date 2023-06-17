#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, I; cin >> n >> I;
	vector<int> a(n); for (auto &x: a) cin >> x;

	int L = (8 * I) / n;
	if (L > 20) {
		cout << 0;
		return;
	}

	int K = 1 << L;

	map<int, int> freqs;
	for (int &i: a) {
		freqs[i]++;
	}

	auto r = freqs.begin();
	auto l = r;
	int cur = 0;

	for (int i = 0; i < K and r != freqs.end(); i++, r++) {
		cur += r->second;
	}

	int ans = n - cur;

	// For any instant [l, r) are present
	while (r != freqs.end()) {
		cur -= l->second; l++;
		cur += r->second; r++;
		ans = min(ans, n - cur);
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
