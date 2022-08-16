#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n; cin >> n;
    
    string s;
    for (int i=9; i>=1; i--) {
        if (n <= i) break;
        s += (char)(i + '0');
        n -= i;
    }
    s += (char) (n + '0');
    reverse(s.begin(), s.end());
    cout << s;    
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

