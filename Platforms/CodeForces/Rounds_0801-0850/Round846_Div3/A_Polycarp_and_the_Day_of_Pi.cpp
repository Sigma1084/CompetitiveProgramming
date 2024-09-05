#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

string ans = "314159265358979323846264338327";

void solve() {
	string s; cin >> s;
	int n = 0;
	while (n < s.size() and s[n] == ans[n]) {
		n++;
	}
	cout << n;
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
