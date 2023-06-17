#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

// Greatest Triangular Number Less than or equal to
int greatestTriLE(int s) {
	int k = ceil(sqrt(2 * s));
	while (k*(k+1) > 2*s) k--;
	return k;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	ll n; cin >> n;

	int ans = 0;
	for (int p = 2, pow; 1LL * p * p <= n; p++) {
		for (pow = 0; n % p == 0; pow++)
			n /= p;
		ans += greatestTriLE(pow);
	}
	if (n > 1) ans++;

	cout << ans;

	return 0;
}
