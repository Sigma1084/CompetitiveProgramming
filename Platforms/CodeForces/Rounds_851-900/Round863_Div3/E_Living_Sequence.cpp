#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	ll n; cin >> n;

	// Need to convert n to base 9
	string s;
	while (n) {
		int x = n % 9;
		s += '0' + (x < 4 ? x : x + 1);
		n /= 9;
	}
	reverse(s.begin(), s.end());

	cout << s;
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
