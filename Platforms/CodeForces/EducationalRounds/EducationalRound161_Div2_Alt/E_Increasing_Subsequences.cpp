#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll k;
    cin >> k;

    int x = 300;
    vector<int> ans;
    while (k > 1) {
        if (k & 1) {
            ans.push_back(1);
            --k;
            continue;
        }
        while (k % 2 == 0) {
            k /= 2;
            ans.push_back(x--);
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto x: ans) {
        cout << x << ' ';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
