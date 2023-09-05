#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll n,v;
ll dp[105][105];

ll f(ll u, ll fuel)
{
    if(u == n) return 0;
    if(dp[u][fuel] != -1) return dp[u][fuel];

    ll &ans = dp[u][fuel];

	ans = 1e18;
    for(int i = 0; i <= v-fuel; i++){
        ll newVal = fuel+i-1;
        if(newVal >= 0){
            ll val = f(u+1, newVal) + (i * u);
            ans = min(ans, val);
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> v;
    memset(dp, -1, sizeof(dp));
    ll ans = f(1, 0);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
