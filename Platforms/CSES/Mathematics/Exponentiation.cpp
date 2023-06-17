#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

int binExp(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	ll ans = binExp(a, b/2);
	ans = ans*ans % MOD;
	if (b%2) ans = ans*a % MOD;
	return (int) ans;
}

void solve() {
	int a, b;
	cin >> a >> b;
	if (a == 0 and b == 0) cout << 1;
	else cout << binExp(a, b);
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
	cout.flush();

	return 0;
}

