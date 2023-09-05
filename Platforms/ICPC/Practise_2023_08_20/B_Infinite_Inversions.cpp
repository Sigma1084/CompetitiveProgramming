#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using oset = tree<int, null_type, less<>, rb_tree_tag,
	tree_order_statistics_node_update>;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int nQ; cin >> nQ;
	map<int, int> m;
	for (int i = 0, x, y; i < nQ; i++) {
		cin >> x >> y;
		if (m.find(x) == m.end()) m[x] = x;
		if (m.find(y) == m.end()) m[y] = y;
		swap(m[x], m[y]);
	}

	ll ans = 0;
	oset s;
	for (auto [p, x]: m) {
		/**
		 * There are elements 1, 2, 3, 4, ..., p - 1 except befP
		 * But there are befX elements before
		 * 
		 * There are elements p + 1, p + 2, ... after p except aftX
		 * But there are aftX elements after
		 */

		if (x < p) {
			// There are p - 1 elements before
			// Number of positions cursed in [x, p]
			int nGreater = s.order_of_key(x + 1);
			int nLesser = s.order_of_key(p);
			int nRed = nLesser - nGreater;
		}
	}

	return 0;
}
