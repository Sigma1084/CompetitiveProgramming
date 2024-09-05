#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> p(k);
    for (auto &x: p) {
        cin >> x;
    }

    for (int i = 1; i + 1 < k; ++i) {
        if (p[i] - p[i-1] > p[i+1] - p[i]) {
            cout << "No";
            return;
        }
    }

    // We need to fill n - k + 1 elements
    if (k >= 2) {
        int x = p[1] - p[0];
        if (1LL * x * (n - k + 1) < p[0]) {
            cout << "No";
            return;
        }
    }

    cout << "Yes";
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
