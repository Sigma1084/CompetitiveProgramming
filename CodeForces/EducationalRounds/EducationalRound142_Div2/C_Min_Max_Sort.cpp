#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (int &i: a) cin >> i;

	vector<int> pos(n);
	for (int i = 0; i < n; i++) {
		pos[--a[i]] = i;
	}
	
	int ans = n / 2;
	int i = n/2 - 1, j = (n+1) / 2;

	while (i >= 0) {
		if (pos[i] < pos[i+1] and pos[j] > pos[j-1]) {
			ans--;
		} else {
			break;
		}
		i--; j++;
	}

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
