#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<int> a(n); for (int &x: a) cin >> x;
	vector<int> b(m); for (int &x: b) cin >> x;
	sort(a.begin(), a.end());

	for (int x: b) {
		cout << upper_bound(a.begin(), a.end(), x) - a.begin() << ' ';
	}

	return 0;
}
