#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;

    vector<int> t;
    for (auto &i: a) {
        if (t.empty() or i >= t.back()) t.push_back(i);
        else *upper_bound(t.begin(), t.end(), i) = i;
    }
    cout << t.size();
}
 
int main() {
    int t = 1;
    // cin >> t;
    
    for (int i=1; i<=t; i++) {
        solve();
        cout << '\n';
    }	
}