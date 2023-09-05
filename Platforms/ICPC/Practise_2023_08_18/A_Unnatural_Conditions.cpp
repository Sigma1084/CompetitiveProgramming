#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

constexpr int N = 2230;

void solve() {
	int n, m; cin >> n >> m;
	string a = string(N - 1, '5');
	string b = string(N - 1, '4');
	b.back() = '5';

	cout << a << '\n' << b << '\n';
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
