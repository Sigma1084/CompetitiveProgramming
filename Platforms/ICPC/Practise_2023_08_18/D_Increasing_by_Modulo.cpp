#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for (int &x: a) cin >> x;

	auto isPossible = [&] (int k) {
		for (int i = 0, cur = 0; i < n; i++) {
			// What is the minimum value of cur possible
			if (a[i] <= cur) {
				if (a[i] + k >= cur) continue;  // Done
				else return false;  // Impossible
			} else {
				// Can we retain cur
				if (a[i] + k - m >= cur) continue;  // Achieve cur
				else cur = a[i];  // Increase cur
			}
		}
		return true;
	};

	int l = 0, h = m - 1, k;
	while (l <= h) {
		k = (l + h) / 2;
		if (isPossible(k)) {
			h = k - 1;
		} else {
			l = k + 1;
		}
	}

	cout << l << '\n';

	return 0;
}
