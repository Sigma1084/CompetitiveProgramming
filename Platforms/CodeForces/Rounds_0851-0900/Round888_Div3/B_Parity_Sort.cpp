#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	vector<int> odds, evens;
	for (int x: a) {
		if (x % 2) odds.push_back(x);
		else evens.push_back(x);
	}

	sort(odds.begin(), odds.end(), greater<>());
	sort(evens.begin(), evens.end(), greater<>());

	for (int &x: a) {
		if (x % 2) {
			x = odds.back();
			odds.pop_back();
		} else {
			x = evens.back();
			evens.pop_back();
		}
	}

	if (is_sorted(a.begin(), a.end())) {
		cout << "YES";
	} else {
		cout << "NO";
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
