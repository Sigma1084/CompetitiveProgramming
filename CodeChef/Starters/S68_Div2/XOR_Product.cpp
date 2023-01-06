#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int P = 998244353;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	vector<int> e;
	ll ans = 1, ones = 0;
	for (int &i: a) {
		if (i == 1) ones++;
		else if (i % 2 == 1) (ans *= i) %= P;
		else e.push_back(i);
	}

	sort(all(e));
	for (auto &i: e) {
		if (ones) (ans *= i+1) %= P, ones--;
		else (ans *= i) %= P;
	}

	cout << ans;
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

