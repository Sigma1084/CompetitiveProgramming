#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n); for (auto &x: a) cin >> x;

	const int N = *max_element(all(a));
	vector<int> f(1 + N, 0);
	for (int &i: a) f[i] += 1;

	int mn = 0, i = 0, w = 0, pos;
	while (i <= N and m >= i) {
		pos = (i == 0 ? f[0] : min(f[i], m / i));
		w += pos;
		m -= pos * i;
		mn = i++;
		while (i <= N and f[i] == 0) i++;
	}
	int place = n + 1 - w;

	cout << m << ' ' << mn << ' ' << w << '\n';

	if (w == n or w == 0) {
		// Nothing can be done
	} else if (a[w] < i or m + mn >= i) {
		place--;
	}

	cout << place;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		if (i == 206) {
			int n, m; cin >> n >> m;
			int a[n]; for (int &i: a) cin >> i;
			cout << n << m;
			for (int &i: a) cout << i;
			cout << '\n';
		} else {
			solve(); cout << '\n';
		}
	}
	return 0;
}
