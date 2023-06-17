#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

ll ans = MOD;
int n;
vector<int> a;
ll s1, s2;

void rec(int i) {
    if (i == n) {
        ans = min(ans, abs(s1 - s2));
        return;
    }
    s1 += a[i]; rec(i + 1); s1 -= a[i];
    s2 += a[i]; rec(i + 1); s2 -= a[i];
}

void solve() {
    cin >> n;
    a.resize(n); for (auto &x: a) cin >> x;

    // 2 ^ 20 combinations  =>  1e6
    ans = MOD;

    // Brute Force
    rec(0);

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

