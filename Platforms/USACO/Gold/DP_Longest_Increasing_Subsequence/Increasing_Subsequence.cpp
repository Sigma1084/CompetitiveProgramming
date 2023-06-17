#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (int &x: a) cin >> x;

	vector<int> lis; lis.push_back(a[0]);
	for (int i: a) {
		if (i > lis.back()) lis.push_back(i);
		else *lower_bound(lis.begin(), lis.end(), i) = i;
	}

	cout << lis.size();
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
