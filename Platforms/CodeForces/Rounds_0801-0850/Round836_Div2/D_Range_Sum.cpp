#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
    /**
     * Inspired from 
     * 1 + 3 + ... 2n-1 = n^2
     */

    if (n % 2 == 0) {
        /**
         * Evens. 2n
         * n, n+1, ... 2n-1, 2n+1, ... 3n
         */
        n /= 2;
        for (int i = 0; i < n; i++) {
            cout << n + i << ' ';
        }
        for (int i = 1; i <= n; i++) {
            cout << 2*n + i << ' ';
        }
    } else {
        /**
         * Odds. 
         * n = 2k + 1
         */
        int k = n/2;
        int a[n + 1];
        int midVal = 4*n;
        a[1] = midVal - n;
        a[n] = midVal + n;
        for (int i = 0; k+1 - i >= 2; i++) {
            a[k+1 - i] = midVal - i;
            a[k+1 + i] = midVal + i;
        }

        for (int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
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

