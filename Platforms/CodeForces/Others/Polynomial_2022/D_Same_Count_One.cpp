#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int MOD = 1e9 + 7;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));

	vector<int> numOnes(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j], numOnes[i] += a[i][j];
	
	int totalOnes = accumulate(numOnes.begin(), numOnes.end(), 0);
	if (totalOnes % n != 0) {
		cout << -1;
		return;
	}
	int reqOnes = totalOnes / n;

	int ans = 0;
	vector<vector<int>> onesAvail(m);
	for (int i = 0; i < n; i++) {
		if (numOnes[i] <= reqOnes) {
			ans += reqOnes - numOnes[i];
			continue;
		}
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1)
				onesAvail[j].push_back(i);
		}
	}

	cout << ans << '\n';

	int k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m and numOnes[i] < reqOnes; j++) {
			if (a[i][j] == 1) continue;
			// a[i][j] = 0
			// We search for some k that such that a[k][j] = 1
			k = -1;
			while (not onesAvail[j].empty()) {
				k = onesAvail[j].back(); onesAvail[j].pop_back();
				if (numOnes[k] > reqOnes) break;
				k = -1;
			}
			if (k == -1) continue;
			a[k][j] = 0; numOnes[i]++; numOnes[k]--;
			cout << k+1 << ' ' << i+1 << ' ' << j+1 << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

