#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	vector<array<int, 2>> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = {a[i], i};
	}
	sort(all(b));

	int rep = -1, f = 2;
	for (int i = 1; i < n; i++) {
		if (b[i][0] == b[i-1][0]) {
			rep = i;
			break;
		}
	}
	// rep and rep - 1 are equal

	while (rep + 1 < n and b[rep][0] == b[rep + 1][0] and f < 4) {
		f++; rep++;
	}

	if (f == 4) {
		// rep, rep - 1, rep - 2, rep - 3 are all equal
		cout << "YES\n";
		cout << b[rep][1] + 1 << ' ' << b[rep - 3][1] + 1 << ' ' << b[rep - 2][1] + 1 << ' ' << b[rep - 1][1] + 1;
		return;
	}

	// Is there any other pair of equal elements?
	for (int i = rep + 1; i < n; i++) {
		if (b[i][0] == b[rep][0]) continue;
		if (b[i][0] == b[i-1][0]) {
			// rep, rep - 1, i and i - 1 are all equal
			cout << "YES\n";
			cout << b[rep][1] + 1 << ' ' << b[i - 1][1] + 1 << ' ' << b[i][1] + 1 << ' ' << b[rep - 1][1] + 1;
			return;
		}
	}

	// We ensure there is at most one pair/triplet of equal elements

	constexpr int N = 25e5;
	vector<vector<pair<int, int>>> diffs(N + 1);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int d = b[j][0] - b[i][0];
			for (const auto &[x, y]: diffs[d]) {
				if (x != i and x != j and y != i and y != j) {
					// x, y, i, j is the answer
					cout << "YES\n";
					cout << b[x][1] + 1 << ' ' << b[j][1] + 1 << ' ' << b[i][1] + 1 << ' ' << b[y][1] + 1;
					return;
				}
			}
			diffs[d].push_back({i, j});
		}
	}

	cout << "NO";
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
