#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	if (n % 2 == 1) {
		cout << "YES";
	} else {
		int x = 0;
		for (int &i: a)
			x ^= i;
		if (x == 0) {
			cout << "YES";
		} else {
			cout << "NO";
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
