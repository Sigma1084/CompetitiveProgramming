#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, x; cin >> n >> x;
	vector<int> a(n); for (auto &x: a) cin >> x;

	array<int, 2> ns = {n / 2, (n + 1) / 2};
	array<map<int, int>, 2> m;
	m.fill(map<int, int>());

	for (int i = 0; i < 2; i++) {
		vector<int> s(1 << ns[i]);
		for (int x = 1; x < (1 << ns[i]); x++) {
			s[x] = s[x - (x & -x)];
			
		}
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
