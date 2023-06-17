#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;
	sort(all(a));

	auto check = [&] (int k) -> bool {
		multiset<int> m(all(a));
		int s = 0;
		while(k and not m.empty()) {
			m.erase(m.upper_bound(k), m.end());  // Deletes all the elements greater than k
			if (not m.empty()) m.erase(*m.rbegin()), k--;  // Alice takes the last element
			for (int i: m) cout << i << ' ';
			if (not m.empty()) m.erase(m.begin());  // Bob takes the first element
		}
		return not k;
	};

	for (int i = 0; i <= n; i++) {
		cout << check(i) << '\n';
	}

	vector<int> ans(n); iota(all(ans), 0);
	cout << *partition_point(all(ans), [&] (int x) { return check(x); });
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
