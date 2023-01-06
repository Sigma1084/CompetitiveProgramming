#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9 + 7;

void solve() {
	int n, m, k; cin >> n >> m >> k;

	vector<vector<pair<int, int>>> pos(k+1);

	for (int _ = 0; _ <= k; _++) {
		string s[n];
		for (int i = 0; i < n; i++)
			cin >> s[i];
		
		for (int i = 1; i+1 < n; i++) {
			for (int j = 1; j+1 < m; j++) {
				if (s[i][j] != s[i-1][j] and s[i][j] != s[i+1][j] and 
					s[i][j] != s[i][j-1] and s[i][j] != s[i][j+1]) {
						pos[_].emplace_back(i, j);
					}
			}
		}
	}

	int s, e;
	vector<vector<pair<int, pair<int, int>>>> E(k+1);
	// Now, the positions are arranged in ascending order
	for (int u = 0; u <= k; u++) {
		for (int v = u+1; v <= k; v++) {
			// Checking if u and v are connected
			if (abs(pos[u].size() - pos[v].size()) != 1)
				continue;
			
			// There is a possibility that they might be the same
			if (pos[u].size() == pos[v].size() + 1) {
				s = 0, e = pos[v].size();
				while (pos[v][s] == pos[u][s]) s++;
				while (pos[v][e] == pos[u][e-1]) e--;
				if (s == e) {
					E[v].push_back({u, pos[v][s]});
				}
			} else {
				s = 0, e = pos[u].size();
				while (pos[u][s] == pos[v][s]) s++;
				while (pos[u][e] == pos[v][e-1]) e--;
				if (s == e) {
					E[u].push_back({v, pos[u][s]});
				}
			}
		}
	}

	for (int i = 0; i <= k; i++) {
		cout << 
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

