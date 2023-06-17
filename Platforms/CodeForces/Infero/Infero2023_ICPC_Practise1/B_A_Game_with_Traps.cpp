#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int m, n, numTraps, maxTime; cin >> m >> n >> numTraps >> maxTime;
	vector<int> a(m); for (auto &x: a) cin >> x;
	vector<array<int, 3>> traps;
	{
		int l, r, d;
		for (int i = 0; i < numTraps; i++) {
			cin >> l >> r >> d;
			if (l > r) continue;  // Trap is already dead
			traps.push_back({l, r, d});
		}
	}
	sort(all(traps));

	/**
	 * We need to Binary Search over the agility level.
	 * Now we have traps sorted by their trap starts
	 * 
	 * How do we simulate the game for the agility level?
	 */

	auto simp = [&] (int agilityLevel) -> bool {
		int time = n + 1;  // Time spent with soldiers
		int l = -1, r = -1;
		for (const auto &[L, R, damage]: traps) {
			if (damage <= agilityLevel) continue;
			if (l == -1 and r == -1) {
				l = L; r = R;
			} else if (L <= r) {
				r = max(r, R);
			} else {
				time += 2 * (r - l + 1);
				l = L; r = R;
			}
		}
		if (l != -1 and r != -1) {
			time += 2 * (r - l + 1);
		}
		return time <= maxTime;
	};

	int l = 0, r = 3e5;
	while (l < r) {
		int mid = (l + r) / 2;
		if (simp(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	// l is the minimum agility level

	int ans = 0;
	for (int &i: a)
		if (i >= l) ans++;

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
