#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;
	vector<int> left(n), right(n);

	left.front() = a.front() == 0 ? 0: 1e9;
	for (int i = 1; i < n; i++) {
		if (a[i] == 0) left[i] = 0;
		else left[i] = left[i - 1] + 1;
	}

	right.back() = a.back() == 0 ? 0: 1e9;
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] == 0) right[i] = 0;
		else right[i] = right[i + 1] + 1;
	}

	for (int i = 0; i < n; i++) {
		cout << min(right[i], left[i]) << ' ';
	}

	return 0;
}
