#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
    tree_order_statistics_node_update> oset;


void solve() {
    int n, k; cin >> n >> k;

    oset s; for (int i=1; i<=n; i++) s.insert(i);
    int curInd = 0;

    while (!s.empty()) {
        curInd += k;
        curInd %= s.size();
        auto x = s.find_by_order(curInd);
        cout << *x << ' ';
        s.erase(x);
    }
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

