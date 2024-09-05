#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    ll ans = a[0], s = 0;
    for (auto x: a) {
        s += x;
        ans = max(ans, s);
        if (s < 0) {
            s = 0;
        }
    }

    cout << ans << '\n';

    return 0;
}
