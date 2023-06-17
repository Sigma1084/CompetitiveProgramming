#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	array<int, 4> a;

	for (int &i: a) {
		cin >> i;
		if (i > n / 2) i = n + 1 - i;
	}

	cout << abs(min(a[0], a[1]) - min(a[2], a[3]));
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
