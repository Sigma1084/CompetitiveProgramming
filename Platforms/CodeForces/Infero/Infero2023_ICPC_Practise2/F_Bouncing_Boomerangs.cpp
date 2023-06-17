#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	/**
	 * Both are the indices in which both doubles and triples can benifit from
	 * 
	 * When we are dealing with the i-th element, we only use the lower bottom of the board
	 *
	 * If we want a single, we always place a target at the diagonal
	 * If we want a double, we find a single in the row to it's right and not consider 
	 *   that single for anything. Then place at (j, i) where (j, j) was the single.
	 *   We can use this column (i) for some next triple.
	 * If we want a triple, we find an isolated element in some column (j)
	 *   and place at (i, i), (i, j). We can use this column (i) for some next triple.
	 */

	set<int> bothRowCols, tripCols;
	vector<array<int, 2>> ans;

	for (int i = n - 1, j; i >= 0; i--) {
		assert(a[i] >= 0 and a[i] <= 3);
		if (a[i] == 1) {
			bothRowCols.insert(i);
			ans.push_back({i, i});
		} else if (a[i] == 2) {
			if (bothRowCols.empty()) {
				cout << -1 << '\n';
				return;
			}
			j = *bothRowCols.rbegin();
			bothRowCols.erase(j);
			tripCols.insert(i);  // We can use this column for a next triple
			ans.push_back({j, i});
		} else if (a[i] == 3) {
			if (not tripCols.empty()) {
				j = *tripCols.rbegin();
				tripCols.erase(j);
			} else if (not bothRowCols.empty()) {
				j = *bothRowCols.rbegin();
				bothRowCols.erase(j);
			} else {
				cout << -1 << '\n';
				return;
			}
			tripCols.insert(i);  // We can use this column for a next triple
			ans.push_back({i, i});
			ans.push_back({i, j});
		}
	}

	cout << ans.size() << '\n';
	for (const auto &[l, r]: ans) 
		cout << l + 1 << ' ' << r + 1 << '\n';
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	solve();
	std::cout << std::endl;
	
	return 0;
}
