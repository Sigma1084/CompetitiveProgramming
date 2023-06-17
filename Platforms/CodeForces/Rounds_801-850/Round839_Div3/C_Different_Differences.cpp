#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9 + 7;

void solve() {
    int k, n; cin >> k >> n;
    vector<int> a(k); 
    for (int i = 0; i < k; i++) a[i] = i+1;

    // Char = 1 is already present
    // Try to increase it

    a[k-1] = n;
    for (int i = k-2, j = n, d = 1; i >= 0; d++, i--) {
        if (a[i+1] - d < a[i]) {
            // Not possible
            break;
        }
        a[i] = a[i+1] - d;
    }

    for (int &i: a) cout << i << ' ';
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

