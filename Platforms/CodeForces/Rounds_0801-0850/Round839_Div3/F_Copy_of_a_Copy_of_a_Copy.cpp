#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9 + 7;

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<string>> s(k+1, vector<string>(n));

	for (int i = 0; i <= k; i++)
		for (int j = 0; j < n; j++)
			cin >> s[i][j];

	vector<vector<pair<int, int>>> E(k+1);

	function<bool(int,int,int)> eqSurr = [&s] (int _k, int x, int y) -> bool {
		return s[_k][x+1][y] == s[_k][x-1][y] and s[_k][x][y-1] == s[_k][x][y+1]
			and s[_k][x+1][y] == s[_k][x][y+1];
	};

	for (int k1 = 0; k1 < k; k1++) {
		for (int k2 = k1+1; k2 <= k; k2++) {
			// Checking if k1 and k2 are related
			int k1Tok2 = 0, k2Tok1 = 0;
			bool unreachable = false;
			for (int i = 1; i+1 < n; i++) {
				for (int j = 1; j+1 < m; j++) {
					if (s[k1][i][j] == s[k2][i][j]) continue;
					// Not equal
					if (eqSurr(k1, i, j) and eqSurr(k2, i, j)) {
						if (s[k2][i][j] == s[k2][i+1][j])
							k1Tok2++;
						else 
							k2Tok1++;
					} else {
						unreachable = true;
					}
				}
			}
			if (unreachable) continue;
			if (k1Tok2 == 0)
				E[k2].emplace_back(k1, k2Tok1);
			if (k2Tok1 == 0)
				E[k1].emplace_back(k2, k1Tok2);
		}
	}

	// for (int u = 0; u <= k; u++) {
	// 	cout << u << ": ";
	// 	for (auto &[v, w]: E[u]) {
	// 		cout << v << ' ' << w << "  ";
	// 	}
	// 	cout << '\n';
	// }

	vector<int> p(k+1);
	for (int i = 0; i <= k; i++) {
		p[i] = i;
	}

	for (int i = 0; i <= k; i++) {
		for (auto &[j, w]: E[i]) {
			p[j] = i;
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

