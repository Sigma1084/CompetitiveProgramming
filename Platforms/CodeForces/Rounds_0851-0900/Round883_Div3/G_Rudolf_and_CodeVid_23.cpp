#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

using BS = bitset<10>;
using Edge = tuple<int, BS, BS>;

void solve() {
	int n, m; cin >> n >> m;
	BS init; cin >> init;

	vector<Edge> edges(m);
	for (auto &[cost, cure, side]: edges)
		cin >> cost >> cure >> side;

	vector<bool> vis(1 << n, false);
	using Node = pair<int, int>;
	priority_queue<Node> pq;

	pq.emplace(-0, init.to_ulong());
	while (not pq.empty()) {
		auto [t, stateVal] = pq.top(); pq.pop();
		auto state = BS(stateVal);
		if (vis[stateVal]) continue;
		vis[stateVal] = true;

		if (state == 0) {
			cout << -t;
			return;
		}

		for (auto [cost, cure, side]: edges) {
			pq.emplace(t - cost, (int) ((state & ~cure) | side).to_ulong());
		}
	}

	cout << -1;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}

	return 0;
}
