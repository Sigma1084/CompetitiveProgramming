#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	ll n, p, w, d;
	cin >> n >> p >> w >> d;

	// xw + yd = p
	// Make w and d coprime
	ll g = gcd(w, d);
	if (p % g) {
		// No integer solutions x and y exist
		cout << -1;
		return 0;
	} else {
		w /= g;
		d /= g;
		p /= g;
	}

	/**
	 * xw + yd = p
	 * 
	 * Now, gcd(w, d) = 1
	 * x = x0 (mod d)
	 * y = y0 (mod w)
	 * 
	 * Suppose x = x0 + td
	 * x0w + yd = p
	 * y0 = (p - x0 w) / d
	 * 
	 * xw = p (mod d)
	 * x = x0 = pw^-1 (mod d)
	 */
	ll x0 = p % d;
	for (ll i = 1; i < d; i++) {
		if (i*w % d == 1) {
			x0 = x0*i % d;
			break;
		}
	}

	// We have an x0 modulo d
	ll y0 = (p - x0*w) / d;

	// We want x0 to be as large as possible

	if (y0 <= 0) {
		// (x0 - td, y0 + tw)
		ll t = (-y0 + w - 1) / w;  // (ceil of y0/w)
		y0 += t * w;
		x0 -= t * d;
	} else {
		// (x0 + td, y0 - tw)
		ll t = y0 / w;
		y0 -= t * w;
		x0 += t * d;
	}

	if (x0 >= 0 and x0 + y0 <= n) {
		cout << x0 << ' ' << y0 << ' ' << (n - x0 - y0) << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}
