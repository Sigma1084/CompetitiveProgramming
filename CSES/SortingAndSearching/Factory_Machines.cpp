#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;
 
void solve() {
    int n, req; cin >> n >> req;
    vector<int> a(n); for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    
    if (req == 0) {
        cout << 0;
        return;
    }
    
    auto pos = [&] (ll t) -> ll {
        ll ans = 0;
        for (auto &x: a) ans += (ll)t / x;
        return ans;
    };
    
    ll l = 0;
    ll r = (ll) a.front() * req;
    
    ll mid, ans;
    while (l <= r) {
        mid = (l + r) / 2;
        if (pos(mid) >= (ll)req) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    
    cout << ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i=1; i<=t; i++) {
        solve();
        cout << '\n';
    }
    cout << endl;
}