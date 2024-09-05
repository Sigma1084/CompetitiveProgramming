#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, s, r; cin >> n >> s >> r;
	int m = s - r;
	vector<int> a(n); a[n-1] = s - r;
	for (int j = 0; j < 6; j++) {
		for (int i = n-2; i >= 0; i--) {
			if (r) a[i] += 1, r--;
		}
	}
	for (auto &i: a) cout << i << ' ';
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
