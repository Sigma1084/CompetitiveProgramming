#include <bits/stdc++.h>
using ll = int64_t;
using std::vector, std::min;

std::ifstream cin("checklist.in");
std::ofstream cout("checklist.out");
// using std::cin; using std::cout;

using Node = std::array<ll, 2>;
ll cost (Node a, Node b) {
	return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int H, G; cin >> H >> G;

	vector<Node> h(H + 1, {0}), g(G + 1, {0});
	for (int i = 1; i <= H; i++) {
		cin >> h[i][0] >> h[i][1];
	}
	for (int i = 1; i <= G; i++) {
		cin >> g[i][0] >> g[i][1];
	}

	/**
	 * dpH[i][j] := Min cost to finish i of h and j of g ending at h[i]
	 * dpG[i][j] := Min cost to finish i of h and j of g ending at g[j]
	 */

	constexpr ll INF = 1LL << 58;
	vector<vector<ll>> dpH(H + 1, vector<ll>(G + 1, INF));
	vector<vector<ll>> dpG(H + 1, vector<ll>(G + 1, INF));
	dpH[1][0] = 0;  // The first h is fixed

	for (int i = 0; i <= H; i++) {
		for (int j = 0; j <= G; j++) {
			if (i > 1) dpH[i][j] = min(dpH[i][j], dpH[i-1][j] + cost(h[i-1], h[i]));
			if (i and j) dpH[i][j] = min(dpH[i][j], dpG[i-1][j] + cost(g[j], h[i]));

			if (j > 1) dpG[i][j] = min(dpG[i][j], dpG[i][j-1] + cost(g[j-1], g[j]));
			if (j and i) dpG[i][j] = min(dpG[i][j], dpH[i][j-1] + cost(h[i], g[j]));
		}
	}

	cout << dpH[H][G];  // Finish at h[H]

	return 0;
}
