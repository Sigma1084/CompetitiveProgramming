#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	ll n, x; cin >> n >> x;
	ll m = 0, M = 1LL << 62;  // min and max

	for (ll i = 0, bit = 1; i < 61; i++, bit <<= 1) {
		if (x & bit) {
			if (n & bit) {
				// n and x have the bit
				// n CANT cross some limit
				M = min(M, bit - n%bit - 1);
			} else {
				// x has the bit but n does not (IMPOSSIBLE)
				cout << -1;
				return;
			}
		} else {
			if (n & bit) {
				// n has the bit but x doesn't
				// n HAS to cross some limit
				m = max(m, bit - n%bit);
			} else {
				// Both don't have the bit so lite
			}
		}
	}

	if (m <= M) {
		cout << m + n;
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
