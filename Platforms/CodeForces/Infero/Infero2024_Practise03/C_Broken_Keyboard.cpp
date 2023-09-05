#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	string a; cin >> a;
	set<char> s;
	int n = a.size();

	for (int i = 0; i < n; i++) {
		if (i == n - 1) { s.insert(a[i]); break; }
		if (a[i] == a[i + 1]) i++;
		else s.insert(a[i]);
	}

	for (char c: s) cout << c;
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
