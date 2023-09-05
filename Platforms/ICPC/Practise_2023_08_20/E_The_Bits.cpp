#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	string a, b;
	cin >> a >> b;


	vector<vector<int>> z(2, vector<int>(2));
	for (int i = 0; i < n; i++) {
		z[a[i] - '0'][b[i] - '0'] += 1;
	}

	ll ans = 0;
	ll doub = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '0' and b[i] == '0') {
			ans += z[1][1];
			doub += z[1][0];
		} else if (a[i] == '1' and b[i] == '0') {
			ans += z[0][1];
			doub += z[0][0];
		}
	}

	cout << ans + doub / 2;

	return 0;
}
