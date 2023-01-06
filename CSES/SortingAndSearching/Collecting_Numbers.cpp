#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;

    vector<int> occ(n+1, -1); 
    // occ[i] = 1 IMPLIES it is root
    // occ[i] = 0 IMPLIES it is derived
    // In the end, count all the roots

    for (int &x: a) {
        if (occ[x-1] == -1) occ[x] = 1;
        else occ[x] = 0;
    }

    // for (auto &x: occ) cout << x << ' '; cout << '\n';
    cout << accumulate(occ.begin()+1, occ.end(), 0);
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

