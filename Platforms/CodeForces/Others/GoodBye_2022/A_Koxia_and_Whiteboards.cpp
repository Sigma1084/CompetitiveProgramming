#include <bits/stdc++.h>
using namespace std;
 
void solve() {
	int n, m, x; cin >> n >> m;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int _ = 0; _ < n; _++) {
		cin >> x;
		pq.push(x);
	}
	for (int _ = 0; _ < m; _++) {
		cin >> x;
		pq.pop();
		pq.push(x);
	}
	int64_t ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
 
	cout << ans;
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int t = 1;
	cin >> t;
 
	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}
 