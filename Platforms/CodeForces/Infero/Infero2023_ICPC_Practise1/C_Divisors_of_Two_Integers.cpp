#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	multiset<int> b(all(a));
	int x = *b.rbegin();

	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			b.erase(b.find(i));
		}
	}

	cout << x << ' ' << *b.rbegin();
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
