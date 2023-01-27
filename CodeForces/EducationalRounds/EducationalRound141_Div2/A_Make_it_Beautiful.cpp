#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	bool ok = false;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[0]) {
			ok = true;
		}
	}


	if (ok) {
		int m = *min_element(all(a));
		*min_element(all(a)) = -1;
		sort(all(a), greater<int>());
		cout << "YES\n" << m << ' ';
		for (int i = 0; i+1 < n; i++) cout << a[i] << ' ';
	} else {
		cout << "NO";
	}
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
