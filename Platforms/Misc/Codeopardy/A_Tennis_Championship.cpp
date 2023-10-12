#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll a = 1, b = 2;
    ll ans = 0;

    while (b <= n) {
        ans++;
        tie(a, b) = make_tuple(b, a + b);
    }

    cout << ans << '\n';

    return 0;
}
