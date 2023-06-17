#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, k; cin >> n >> k;

	for (int i = n, j = 1, x = 1; j <= i; x = 1 - x) {
		if (x) cout << i-- << ' ';
		else cout << j++ << ' ';
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
