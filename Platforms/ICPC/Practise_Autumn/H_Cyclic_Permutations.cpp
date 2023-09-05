#include <bits/stdc++.h>
using namespace std;
constexpr int P = 1'000'000'007;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	int ans = 1, mount = 1;
	for (int i = 2; i <= n; i++) {
		mount = (2LL * mount) % P;
		ans = (1LL * ans * i) % P; 
	}
	ans = (ans + P - mount) % P;

	cout << ans;

	return 0;
}
