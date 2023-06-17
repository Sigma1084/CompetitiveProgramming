#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, k; cin >> n;

	map<int, int> count;

	vector<vector<int>> c(n);
	for (int i = 0; i < n; i++) {
		cin >> k;
		c[i].resize(k);
		for (int &p: c[i]) {
			cin >> p;
			count[p]++;
		}
	}

	bool ok;
	for (int i = 0; i < n; i++) {
		ok = true;
		for (int &p: c[i]) {
			if (count[p] == 1) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << "Yes";
			return;
		}
	}
	cout << "No";
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
