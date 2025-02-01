#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> ts(m);
    for (auto &x: ts) {
        cin >> x;
    }
    sort(ts.begin(), ts.end());

    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;

        auto it = lower_bound(ts.begin(), ts.end(), x);
        if (it == ts.end()) {
            cout << n - *prev(it);
        } else if (it == ts.begin()) {
            cout << *it - 1;
        } else {
            cout << (*it - *prev(it)) / 2;
        }
        cout << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
