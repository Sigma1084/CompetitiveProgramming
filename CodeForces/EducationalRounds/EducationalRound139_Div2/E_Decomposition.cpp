#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


/**
 * The values for dp
 *          0 : {}
 *    1, 2, 3 : {1} {2} {3}
 *    4, 5, 6 : {1 1} {2 1} {3 1}
 *    7, 8, 9 : {1 2} {2 2} {3 2}
 * 10, 11, 12 : {1 1 2} {2 1 2} {3 1 2}
 * 13, 14, 15 : {1 2 1} {2 2 1} {3 2 1}
 */

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	ll ans = 0;
	array<ll, 16> old, cur;
	cur = {0}; cur[0] = 1;

	for (int &i: a) {
		if (i) {
			assert(i > 0 and i < 4);
			old = cur;
			cur = {0};
		} else {
			for (int j = 0; j < 16; j++)
				cur[j] *= 2;
		}

		if (i == 1) {
			cur[1] = old[1] + old[3] + 1;
			cur[4] = old[4] + old[6];
			cur[5] = old[2] + old[5];
			cur[7] = old[7] + old[9];
			cur[10] = old[10] + old[12];
			cur[11] = old[11];
			cur[13] = old[13] + old[15];
			cur[14] = old[8] + old[14];
		} else if (i == 2) {
			cur[2] = old[2] + old[3] + 1;
			cur[5] = old[5] + old[6];
			cur[7] = old[1] + old[7];
			cur[8] = old[8] + old[9];
			cur[10] = old[4] + old[10];
			cur[11] = old[11] + old[12];
			old[13] = old[13];
			old[14] = old[14] + old[15];
		} else if (i == 3) {
			cur[3] = old[1] + old[2] + old[3] + 1;
			cur[6] = old[4] + old[5] + old[6];
			cur[9] = old[7] + old[8] + old[9];
			cur[12] = old[10] + old[11] + old[12];
			cur[15] = old[13] + old[14] + old[15];
		}

		for (int j = 1; j <= 3; j++) ans += cur[j];
		for (int j = 4; j <= 9; j++) ans += 2*cur[j];
		for (int j = 10; j <= 15; j++) ans += 3*cur[j];
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == 0)
			ans += (ll) (i+1) * (n-i);
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
