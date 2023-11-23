#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    // Number passing through i is cnt[i]
    vector<int> cnt(n + 1);
    for (int x: a) {
        if (x <= n) {
            cnt[x]++;
        }
    }

    for (int i = n; i >= 1; --i) {
        for (int j = 2*i; j <= n; j += i) {
            cnt[j] += cnt[i];
        }
    }

    cout << *max_element(cnt.begin(), cnt.end());
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
