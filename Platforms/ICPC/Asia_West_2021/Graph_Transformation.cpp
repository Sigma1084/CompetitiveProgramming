#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, m, q; cin >> n >> m >> q;

	vector<int> p(n); std::iota(p.begin(), p.end(), 0);
	vector<int> c(n, 0);  // Initially, everything is black
	vector<int> oddCycle(n, 0);  // No odd cycles initially
	vector<int> swap(n, 0);  // All its children are supposed to be swapped once
	int numConnected = n, numOddConnected = 0;

	function<int(int)> find = [&] (int u) -> int {
		if (p[u] == u) return u;

		// If old parent got merged off wrong
		if (swap[p[u]]) c[u] ^= 1;

		// Store old parent and old parent color
		int pO = p[u], cPO = c[p[u]];

		// Standard DSU
		p[u] = find(p[u]);

		// If colour of old parent changes, colour of node changes
		c[u] ^= cPO ^ c[pO];

		return p[u];
	};

	function<void()> debug = [&] () {
		cerr << "Nodes: "; for (int i = 0; i < n; i++) cerr << i + 1 << ' '; cerr << '\n';
		cerr << "Pars : "; for (int i = 0; i < n; i++) cerr << p[i] + 1 << ' '; cerr << '\n';
		cerr << "Cols : "; for (int i = 0; i < n; i++) cerr << c[i] << ' '; cerr << '\n';
		cerr << "Swaps: "; for (int i = 0; i < n; i++) cerr << swap[i] << ' '; cerr << '\n';
		cerr << "NumCon: " << numConnected << "  " << "NumOdd: " << numOddConnected << '\n';
		cerr << '\n';
	};

	function<void(int, int)> merge = [&] (int u, int v) -> void {
		if (find(u) == find(v)) {
			if (oddCycle[p[u]]) return;

			if (c[u] == c[v]) {
				// Same colours means we got a new odd cycle
				oddCycle[p[u]] = 1;
				numOddConnected++;
			} else {
				// Same colours getting merged means do nothing
			}
			return;
		}

		// Swapping need to take place in parent of v if u and v have same colours
		swap[p[v]] = c[u] == c[v];
		c[p[v]] ^= swap[p[v]];

		// Making them parents for ease
		u = p[u]; v = p[v];
		p[v] = u;

		// u will be the main leader
		numConnected--;
		if (oddCycle[u] and oddCycle[v]) numOddConnected--;
		else if (oddCycle[u] ^ oddCycle[v]) oddCycle[u] = 1;
	};

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--; v--;
		merge(u, v);
	}


	for (int i = 0, x, a, b, k, ans; i < q; i++) {
		cin >> x;
		if (x == 1) {
			cin >> a >> b; a--; b--;
			merge(a, b);
		} else {
			cin >> k;
			ans = numConnected;
			if (k) {
				ans += numConnected - numOddConnected;
				k--;
			}
			cout << 1LL * ans * (1 << k) << '\n';
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}

	return 0;
}
