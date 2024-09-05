#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n); for (auto &x: a) cin >> x;

	deque<int> req;
	for (int t = 0; t < k; t++) {
		req.push_back(a.front());
	}

	if (a.front() != a.back()) {
		for (int t = 0; t < k; t++) {
			req.push_back(a.back());
		}
	}

	for (int i = 0; i < n and !req.empty(); i++) {
		if (a[i] == req.front()) req.pop_front();
	}

	if (req.empty()) {
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
