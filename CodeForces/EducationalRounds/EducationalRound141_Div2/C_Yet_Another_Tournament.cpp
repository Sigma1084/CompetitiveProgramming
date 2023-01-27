#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n); for (auto &x: a) cin >> x;

	vector<int> b = a;
	sort(all(b));

	int w = 0;
	while (w < n and b[w] <= m)
		m -= b[w++];

	int place = n + 1 - w;
	if (w == n or w == 0) {
		// Nothing can be done
	} else if (b[w-1] + m >= a[w]) {
		place -= 1;
	}

	cout << place;
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
