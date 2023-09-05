#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	string s; cin >> s;
	map<pair<char, char>, int> f;
	for (int i = 1; i < n; i++) {
		f[{s[i - 1], s[i]}]++;
	}
	map<int, pair<char, char>> g;
	for (auto [p, fr]: f) g[fr] = p;
	auto [a, b] = g.rbegin()->second;
	cout << a << b;
	return 0;
}
