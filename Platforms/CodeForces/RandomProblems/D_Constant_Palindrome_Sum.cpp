#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n); for (auto &x: a) cin >> x;

	Tree<int> os(a.begin(), a.end());

	map<int, int> freq; // frequency of a pair
	for (int i = 0; i+i < n; i++) {
		freq[a[i] + a[n-1-i]]++;
	}

	int ans = 1e9;
	for (auto [s, f]: freq) {
		// We need 1 <= x <= k and 1 <= s - x <= k  -->  s - k <= x <= s - 1
		// Find the number of elements x such that x < s - k and double count them
		ans = min(ans, n - f + (int)os.order_of_key(s - k));
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
