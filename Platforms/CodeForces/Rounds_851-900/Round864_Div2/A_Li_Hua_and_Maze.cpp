#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


vector<pair<int, int>> gridIterator = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};


void solve() {
	int n, m; cin >> n >> m;

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	auto isValid = [&](int x, int y) {
		return 1 <= x and x <= n and 1 <= y and y <= m;
	};

	int c1 = 0, c2 = 0;
	for (auto [dx, dy]: gridIterator) {
		if (isValid(x1 + dx, y1 + dy)) c1++;
		if (isValid(x2 + dx, y2 + dy)) c2++;
	}

	cout << min(c1, c2);
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
