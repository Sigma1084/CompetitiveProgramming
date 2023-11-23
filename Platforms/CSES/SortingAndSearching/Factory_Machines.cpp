#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }

    auto isPos = [&a, k] (ll t) -> bool {
        ll need = k;
        for (int x: a) {
            if (need <= t / x) return true;
            need -= t / x;
        }
        return false;
    };

    auto range = ranges::iota_view<ll, ll>(1LL, 1e18 + 1);
    auto ans = *ranges::lower_bound(range, true, less<>(), isPos);
    
    cout << ans << '\n';

    return 0;
}
