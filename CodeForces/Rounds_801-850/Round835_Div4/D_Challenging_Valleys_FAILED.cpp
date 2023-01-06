#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
    vector<int> a(n+2);
    
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (n == 1) {
        cout << "YES";
        return;
    }

    a[0] = MOD;
    a[n+1] = MOD;

    int l = 1, r = 1;
    bool hap = false;  // Will be true when we find a valley

    while (l < n+1) {
        // If increasing, traverse as much as possible
        while (l < n+1 and a[l] >= a[l-1]) {
            l++;
        }

        // a[l] < a[l-1] and hence, we have the dip as required
        // We found a dip starting at l
        r = l;
        while (a[r] == a[l]) {
            r++;
        }
        // Breaks when a[r] != a[l]. So, subtract 1 from r
        r--;

        // We have a[l-1] > a[l] = a[l+1] = ... = a[r-1] = a[r]
        // For [l, r] to be a valley, we need a[r] < a[r+1]

        if (a[r] < a[r+1]) {
            // We found a valley

            if (hap) {
                // We had found a valley before this
                cout << "NO";
                return;
            }
            
            hap = true;
        }

        // Start processing again from r+1
        l = r+1;
    }

    if (hap) {
        cout << "YES";
    } else {
        cout << "NO";
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

