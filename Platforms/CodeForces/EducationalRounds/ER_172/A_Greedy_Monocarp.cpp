#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end(), greater<>());

    for (int i = 0; i < n and a[i] <= k; ++i) {
        k -= a[i];
    }

    cout << k;
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
