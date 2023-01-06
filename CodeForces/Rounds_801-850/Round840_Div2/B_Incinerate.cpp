#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int P = 1e9 + 7;

void solve() {
	int n, k; cin >> n >> k;
	vector<pair<int, int>> a(n);
	for (auto &[h, _]: a) cin >> h;
	for (auto &[_, p]: a) cin >> p;

	sort(all(a)); // Lesser Health is first

	vector<int> minPowerFrom(n);
	minPowerFrom[n-1] = a[n-1].second;
	for (int i = n-2; i >= 0; i--)
		minPowerFrom[i] = min(minPowerFrom[i+1], a[i].second);

	int totalDam = 0, leastAlive = 0;
	while (leastAlive < n and k > 0) {
		totalDam += k;
		while(leastAlive < n and a[leastAlive].first <= totalDam) leastAlive++;
		k -= minPowerFrom[leastAlive];
	}

	if (leastAlive == n) {
		cout << "YES";
	} else {
		cout << "NO";
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

