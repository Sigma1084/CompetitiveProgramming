#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());

    if (a.front() == a.back()) {
        cout << (ll) n * (n-1);
        return;
    }

    int l = 1, r = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) l++;
        else break;
    }
    for (int i = n-2; i >= 0; i--) {
        if (a[i] == a[i+1]) r++;
        else break;
    }

    cout << (ll) 2 * l * r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

