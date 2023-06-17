#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n = 5;
    vector<int> a(n); for (auto &x: a) cin >> x;

    sort(a.begin(), a.end());
    
    int ans = 0;
    for (int i = 0; i+2 < n; i++) {
        for (int j = i+1; j+1 < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (a[k] < a[i] + a[j])
                    ans++;
            }
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

