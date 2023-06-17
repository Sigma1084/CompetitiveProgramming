#include <bits/stdc++.h>
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n); for (auto &x: a) cin >> x;
	
	int pres = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == pres + 1)
			pres++;
	
	cout << (n - pres + k-1) / k; 
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
