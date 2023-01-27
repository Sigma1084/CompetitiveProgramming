#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int w, d, h; cin >> w >> d >> h;
	int a, b, f, g; cin >> a >> b >> f >> g;

	int ans =  abs(f - a) + abs(g - b) + h;
	int minExtra = INT_MAX;
	minExtra = min(minExtra, min(2*a, 2*(w-a)));
	minExtra = min(minExtra, min(2*f, 2*(w-f)));
	minExtra = min(minExtra, min(2*b, 2*(d-b)));
	minExtra = min(minExtra, min(2*g, 2*(d-g)));
	ans += minExtra;
	cout << ans;
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
