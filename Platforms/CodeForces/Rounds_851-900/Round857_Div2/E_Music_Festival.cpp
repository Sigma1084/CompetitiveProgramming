#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<vector<int>> a(n);
	
	for (auto &v: a) {
		int sz; cin >> sz;
		v.resize(sz);
		for (auto &x: v)
			cin >> x;
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
