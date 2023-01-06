#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n; cin >> n;
    /**
     * n = 2
     * 2*1 + 1*2
     * n = 3
     * 3*1 + 1*2 + 2*3 => 3 + 2 + 3
     * 
     * 1*1 + 2*2 + 3*3 => 1 + 2 + 3
     * 1*1 + 3*2 + 2*3 => 1 + 6 + 6
     */
    if (n%2 == 1) cout << 1 << ' ';
    for (int i = n%2 + 1; i <= n; i += 2) {
        cout << i+1 << ' ' << i << ' ';
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

