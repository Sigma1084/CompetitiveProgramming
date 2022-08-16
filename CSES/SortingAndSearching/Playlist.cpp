#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;
    map<int, int> prev;
    int prevRep = 0, ans = 0;
    for (int i=0; i<n; i++) {
        prevRep = max(prevRep, prev[a[i]]);
        ans = max(ans, i+1 - prevRep);
        prev[a[i]] = i+1;
    }
    cout <<  ans;
}
 
int main() {
    int t = 1;
    // cin >> t;
    
    for (int i=1; i<=t; i++) {
        solve();
        cout << '\n';
    }	
}