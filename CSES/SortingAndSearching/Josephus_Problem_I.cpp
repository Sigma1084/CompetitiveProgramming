#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n; cin >> n;
    set<int> s; for (int i=1; i<=n; i++) s.insert(i);
    for (auto it = s.begin(); s.size(); ) {
        if (++it == s.end()) it = s.begin();
        cout << *it << ' ';
        auto x = it;
        if (++it == s.end()) it = s.begin();
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

