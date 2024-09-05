#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

constexpr int N = (1 << 18) + 1;

void solve() {
	int n; cin >> n;
	int a[n]; for (auto &x: a) cin >> x;

	ll ans = (ll) n * (n+1) / 2;  // nC2
	int f[N] = {0};
	f[0] = 1;

	int curXor = 0;
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < 512; j++)
			ans -= f[a[i] ^ (j*j) ^ curXor];
		f[curXor ^= a[i]] += 1;
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}

