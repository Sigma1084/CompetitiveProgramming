#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, m; cin >> n >> m;
	vector<string> grid(n);

	for (auto &x: grid) cin >> x;
	vector<vector<bool>> reachable(n, vector<bool>(m, false));
	reachable[n-1][m-1] = true;

	auto valid = [&](int r, int c) {
		return r >= 0 and r < n and c >= 0 and c < m;
	};

	for (int r = n-1; r >= 0; r--) {
		for (int c = m-1; c >= 0; c--) {
			if (grid[r][c] == '#') continue;
			if (valid(r+1, c) and reachable[r+1][c]) {
				reachable[r][c] = true;
			} else if (valid(r, c+1) and reachable[r][c+1]) {
				reachable[r][c] = true;
			}
		}
	}

	if (reachable[0][0] == false) {
		cout << 0;
		return;
	}

	int rL = 0, cL = 0, rU = 0, cU = 0;
	while (rL < n-1 or cU < m-1) {
		if (valid(rL+1, cL) and reachable[rL+1][cL]) {
			rL++;
		} else {
			cL++;
		}

		if (valid(rU, cU+1) and reachable[rU][cU+1]) {
			cU++;
		} else {
			rU++;
		}
		
		if (rL == rU and cL == cU) {
			cout << 1;
			return;
		}
	}

	cout << 2;
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
