#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
    if (n % 2 == 1) {
        for (int i = 0; i < n; i++)
            cout << 1 << ' ';
    } else {
        for (int i = 0; i + 2 < n; i++) {
            cout << 2 << ' ';
        }
        cout << 1 << ' ' << 3;
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

