#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, m;
	
	cin >> n;
	vector<pair<int, int>> math(n);
	for (auto &[iq, ad]: math) cin >> iq;
	for (auto &[iq, ad]: math) cin >> ad;
	
	cin >> m;
	vector<pair<int, int>> phy(m);
	for (auto &[iq, ad]: phy) cin >> iq;
	for (auto &[iq, ad]: phy) cin >> ad;

	sort(math.begin(), math.end(), greater<>());  // ad DESC
	sort(phy.begin(), phy.end(), [](auto a, auto b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
	});
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
