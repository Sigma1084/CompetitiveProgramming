#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	/**
	 * xx + ll = xx + 2xh + hh
	 * 2xh = ll - hh
	 * x = (ll - hh) / 2h
	 */
	
	double h, l; cin >> h >> l;
	double x = (l * l - h * h) / (2 * h);
	cout << fixed << setprecision(13) << x;

	return 0;
}
