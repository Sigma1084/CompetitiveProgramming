#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int MOD = 1e9 + 7;

void solve() {
    int a[3], b[3];
    for (int i = 0; i < 3; i++) cin >> a[i] >> b[i];

    if (a[0] == a[1] or a[1] == a[2] or a[0] == a[2]) {
        if (b[0] == b[1] or b[1] == b[2] or b[2] == b[0]) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
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

