#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


/**
 * a < b
 * a + x = t_a^2
 * b + x = t_b^2
 * b - a = (t_b - t_a)(t_b + t_a)
 * d = t_b - t_a
 * D = t_b + t_a
 * 
 * t_a = (D - d) / 2
 * x = (D - d)^2 / 4 - a
 * x = (D + d)^2 / 4 - b
 * 
 * For the pair (a, b), the possible values of x are computed and are incremented in a map.
 */

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	map<ll, int> xVals;

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int diff = a[j] - a[i];
			for (int d = 1; d*d < diff; d++) {
				if (diff % d) continue;
				int D = diff / d;
				if ((d + D) % 2) continue;
				xVals[(ll)(D-d)*(D-d)/4 - a[i]]++;
			}
		}
	}

	int ans = 1;
	for (auto &[x, f]: xVals) {
		if (x < 0) continue;
		f = (int)sqrt(2*f) + 1;
		ans = max(ans, f);
	}
	
	cout << ans;
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
