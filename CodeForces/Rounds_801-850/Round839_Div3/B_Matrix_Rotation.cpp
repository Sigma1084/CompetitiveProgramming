#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9 + 7;

void solve() {
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];

    bool ok = false;
    for (int i = 0; i < 4; i++) {
        if (a[0] < a[1] and a[2] < a[3] and a[0] < a[2] and a[1] < a[3])
            ok = true;
        int t = a[0];
        a[0] = a[2];
        a[2] = a[3];
        a[3] = a[1];
        a[1] = t;

        // cout << a[0] << ' ' << a[1] << '\n';
        // cout << a[2] << ' ' << a[3] << '\n';
    }

    cout << (ok ? "YES" : "NO");
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

