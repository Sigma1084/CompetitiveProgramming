#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

/**
 * n = 2: [1, 2]
 * n = 3: [1, 2, 3]
 * n = 4: [2, 4, 1, 3]
 * n = 5: [1, 2, 4, 3, 5]
 * n = 6: [3, 6, 2, 4, 1, 5]
 * n = 8: [1, 2, 4, 8, 3, 6, 5, 7]
 */
void solve() {
	int n; cin >> n;
	vector<bool> av(n, true);
	vector<int> p;

	for (int i = 1; i <= n; i++) {
		if (!av[i - 1]) continue;
		for (int j = i; j <= n; j *= 2) {
			p.push_back(j);
			av[j - 1] = false;
		}
	}

	for (int x: p) cout << x << ' ';
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
