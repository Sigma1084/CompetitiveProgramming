#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	vector<set<int>> srows(n), scols(m);
	vector<vector<int>> rows(n), cols(m);

	for (int r = 0, x; r < n; r++) {
		for (int c = 0; c < m; c++) {
			cin >> x;
			a[r][c] = x;
			srows[r].insert(x);
			scols[c].insert(x);
		}
	}

	for (int i = 0; i < n; i++) rows[i] = vector(srows[i].begin(), srows[i].end());
	for (int i = 0; i < m; i++) cols[i] = vector(scols[i].begin(), scols[i].end());

	int x, lessRow, lessCol, greaterRow, greaterCol;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			lessRow = lower_bound(rows[r].begin(), rows[r].end(), a[r][c]) - rows[r].begin();
			greaterRow = rows[r].end() - lower_bound(rows[r].begin(), rows[r].end(), a[r][c] + 1);
			lessCol = lower_bound(cols[c].begin(), cols[c].end(), a[r][c]) - cols[c].begin();
			greaterCol = cols[c].end() - lower_bound(cols[c].begin(), cols[c].end(), a[r][c] + 1);
			x = max(lessRow, lessCol) + max(greaterRow, greaterCol) + 1;
			cout << x << ' ';
		}
		cout << '\n';
	}

	return 0;
}
