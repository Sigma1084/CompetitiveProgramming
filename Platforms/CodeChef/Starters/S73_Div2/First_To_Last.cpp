#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

struct Tile: array<int, 2> {
	using Base = array<int, 2>;
	using Base::Base;
	Tile (const Base &b): Base(b) {}
};

void solve() {
	int n, m, k; cin >> n >> m >> k;

	vector<Tile> tiles(k);

	for (int i = 0; i < k; i++) {
		int l, w; cin >> l >> w;
		if (l == n or w == m) {
			tiles.pop_back();
			k--, i--;
		} else {
			tiles[i] = Tile::Base{l, w};
		}
	}

	sort(all(tiles), [] (const Tile &a, const Tile &b) {
		if (a[0] == b[0]) return a[1] > b[1];
		return a[0] < b[0];
	});  // sort by (L asc, W desc)

	vector<int> lis;

	for (int i = 0; i < k; i++) {
		int pos = lower_bound(all(lis), tiles[i][1]) - lis.begin();
		if (pos == lis.size()) {
			lis.push_back(tiles[i][1]);
		} else {
			lis[pos] = tiles[i][1];
		}
	}

	cout << n + m - 2 - lis.size();
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
