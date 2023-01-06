#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef int64_t ll;
const int MOD = 1e9 + 7;

int n, d;
vector<vector<int>> e;
vector<int> p;
vector<bool> rT, bT, b, r;

vector<int> path;
void dfs(int u) {
	if (path.size() > d) {
		if (rT[u]) bT[path[path.size()-d-1]] = true;
		if (bT[u]) rT[path[path.size()-d-1]] = true;
	}
	for (int &v: e[u]) {
		if (p[v] != -1) continue;
		p[v] = u;
		path.push_back(v);
		dfs(v);
		path.pop_back();
	}
}


void update(int u, vector<bool> &T) {
	for (; u and !T[u]; u = p[u]) {
		T[u] = true;
	}
}


void solve() {
	cin >> n >> d;
	e.clear(); e.resize(n);


	int u, v;
	for (int i = 0; i+1 < n; i++) {
		cin >> u >> v; u--; v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	p.resize(n, -1); p[0] = 0;
	rT.resize(n, false);
	bT.resize(n, false);
	r.resize(n, false);
	b.resize(n, false);
	bT[0] = rT[0] = true;

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> u; u--;
		rT[u] = true;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> u; u--;
		bT[u] = true;
	}

	path.clear();
	dfs(0);

	for (int i = 1; i < n; i++) {
		if (rT[i]) update(i, r);
		if (bT[i]) update(i, b);
	}

	// for (int i = 0; i < n; i++) cout << r[i] << ' '; cout << '\n';
	// for (int i = 0; i < n; i++) cout << b[i] << ' '; cout << '\n';

	int ans = 2*accumulate(all(b), 0) + 2*accumulate(all(r), 0);

	cout << ans;
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

