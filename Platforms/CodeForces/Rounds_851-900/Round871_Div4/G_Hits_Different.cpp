#include <bits/stdc++.h>
using namespace std;

vector<int> triNum;

int getRow(int x) {
	return lower_bound(triNum.begin(), 
		triNum.end(), x) - triNum.begin();
}


void solve() {
	int n; cin >> n;
	const int row = getRow(n);
	const int end = n - row * (row - 1) / 2;

	int64_t ans = 0;
	for (int r = row, begin = end; r >= 1; r--, begin--) {
		for (int d = max(1, begin); d <= min(end, r); d++) {
			int x = r * (r - 1) / 2 + d;
			ans += 1LL * x * x;
		}
	}

	cout << ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	constexpr int N = 2023 * 1012;
	for (int i = 1, x = 0; x <= N; x += i++) {
		triNum.push_back(x);
	}

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}

	return 0;
}
