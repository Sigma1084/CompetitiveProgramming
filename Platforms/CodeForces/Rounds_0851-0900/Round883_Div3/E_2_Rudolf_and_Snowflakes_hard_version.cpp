#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

template<typename T>
T binPow(T a, ll b) {
	if (b == 0) return 1;
	auto x = binPow(a, b / 2);
	return x * x * (b % 2 ? a : 1);
}

ll getVal(int k, int b) {
	double dVal = (binPow(double(k), b) - 1) / (k - 1);
	if (dVal >= 2e18) return ll(2e18);
	return (binPow(ll(k), b - 1) - 1) / (k - 1) + binPow(ll(k), b - 1);
}

void solve() {
	/**
	 * Suppose we bloom the k-snowflake b times,
	 * 1 + k + k^2 + k^3 + ... + k^(b-1) = (k^b - 1) / (k - 1)
	 * Only if
	 * 
	 * We need to find a k for every b
	 * b starts from 3
	 */

	ll n, val; cin >> n;

	for (int b = 3; b <= 61; b++) {
		// Find an appropriate k using binary search
		int kLow = 2, kHigh = 1e9;
		while (kLow <= kHigh) {
			int k = (kLow + kHigh) / 2;
			val = getVal(k, b);
			if (val > n) {
				// k is too big
				kHigh = k - 1;
			} else if (val < n) {
				// k is too small
				kLow = k + 1;
			} else {
				// k == val, so we found (k, b)
				cout << "YES";
				return;
			}
		}
		if (getVal(kLow, b) == n) {
			cout << "YES";
			return;
		} else if (kHigh > 1 and getVal(kLow, b) == n) {
			cout << "YES";
			return;
		}
	}

	cout << "NO";
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
