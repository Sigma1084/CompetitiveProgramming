#include <bits/stdc++.h>
using ll = int64_t;
using std::vector;

struct Node: public std::array<int, 2> {
	using Base = std::array<int, 2>;
	using Base::Base;
	Node (const Base &base): Base(base) {}
	Node operator + (Node a) {
		return Base{this->at(0) + a.at(0), this->at(1) + a.at(1)};
	}
};

const std::map<char, Node> iter = {
	{'N', {{0, 1}}},
	{'S', {{0, -1}}},
	{'E', {{1, 0}}},
	{'W', {{-1, 0}}}
};

int dist(Node n1, Node n2) {
	int x = n1[0] - n2[0], y = n1[1] - n2[1];
	return x * x + y * y;
}

std::ifstream cin("radio.in");
std::ofstream cout("radio.out");
// using std::cin; using std::cout;

int main() {
	std::ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m; cin >> n >> m;
	Node f, b; cin >> f[0] >> f[1] >> b[0] >> b[1];
	std::string fs, bs; cin >> fs >> bs;

	/**
	 * dp[i][j] := Minimum distance after farmer moves i steps and bessie moves j steps
	 * posF[i]:= Position of farmer after farmer moves i steps
	 * posB[j] := Position of bessie after bessie moves j steps
	 */

	// DP table
	constexpr ll INF = 1e17;
	vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, INF));
	dp[0][0] = 0;  // Base case

	// Positions of farmer and bessie
	vector<Node> posF(n + 1);
	vector<Node> posB(m + 1);

	posF[0] = f;
	for (int i = 1; i <= n; i++) {
		posF[i] = posF[i - 1] + iter.at(fs[i - 1]);
		dp[i][0] = dp[i-1][0] + dist(posF[i], posB[0]);  // (i-1, 0) -> (i, 0)
	}

	posB[0] = b;
	for (int j = 1; j <= m; j++) {
		posB[j] = posB[j - 1] + iter.at(bs[j - 1]);
		dp[0][j] = dp[0][j-1] + dist(posF[0], posB[j]);  // (0, j-1) -> (0, j)
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = std::min({
				dp[i - 1][j] + dist(posF[i], posB[j]),  // (i-1, j) -> (i, j)
				dp[i][j - 1] + dist(posF[i], posB[j]),  // (i, j-1) -> (i, j)
				dp[i - 1][j - 1] + dist(posF[i], posB[j]),  // (i-1, j-1) -> (i, j)
			});
		}
	}

	cout << dp[n][m];

	return 0;
}
