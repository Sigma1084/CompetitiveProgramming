#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	multiset<int> s(all(a));
	int ans = 0;

	while (s.size()) {
		ans += 1;
		int x = *s.begin();
		s.erase(s.find(x));
		while(s.size() and s.count(x + 1)) {
			s.erase(s.find(++x));
		}
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
