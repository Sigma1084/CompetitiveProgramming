#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;
    auto b = a; sort(b.begin(), b.end());

    if (n == 1) {
        cout << 0;
        return;
    }

    bool rep = b[n-1] == b[n-2];
    int maxEle = b[n-1];

    for (int i = 0; i < n; i++) {
        if (a[i] < maxEle) {
            cout << a[i] - maxEle;
        } else if (rep) {
            cout << 0;
        } else {
            cout << maxEle - b[n-2];
        }
        cout << ' ';
    }
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

