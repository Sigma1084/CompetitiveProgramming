#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	string s; cin >> s;
	set<pair<char, char>> melodies;
	for (int i = 0; i + 1 < n; i++)
		melodies.insert({s[i], s[i + 1]});
	cout << melodies.size();
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
