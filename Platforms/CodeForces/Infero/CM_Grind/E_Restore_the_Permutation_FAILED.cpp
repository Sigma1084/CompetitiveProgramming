#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int P = 1e9 + 7;

void solve() {
	int n; cin >> n; n /= 2;
	vector<array<int, 3>> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i][0], a[i][1] = i;
	sort(a.begin(), a.end());

	for (int i = 1; i < n; i++) {
		if (a[i][0] == a[i-1][0]) {
			cout << -1;
			return;
		}
	}

	vector<bool> isPresent(2*n + 1);
	for (auto &[x, i, _]: a)
		isPresent[x] = true;

	bool ok = true;
	for (int i = 0, j = 1; i < n; i++) {
		while (isPresent[j]) j++;
		a[i][2] = j++;
		if (a[i][2] > a[i][0]) ok = false;
	}

	if (not ok) {
		cout << -1;
		return;
	}

	sort(a.begin(), a.end(), [] (auto &i, auto &j) { return i[1] < j[1]; });

	for (int i = 0; i < n; i++) {
		cout << a[i][2] << ' ' << a[i][0] << ' ';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}

