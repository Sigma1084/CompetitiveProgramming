#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    // ceil(n / k) is the answer

    auto getVec = [](int n, int start) {
        vector<int> a(n);
        for (int i = 0, x = (n - 1) / 2; i < n; ++i) {
            a[i] = x;
            x--;
            if (x < 0) {
                x = n - 1;
            }
        }
        for (auto &x: a) {
            x += start;
        }
        return a;
    };

    vector<int> a(n);
    for (int i = 0; i < n; ) {
        auto v = getVec(min(k, n - i), i+1);
        for (auto x: v) {
            a[i++] = x;
        }
    }

    for (auto x: a) {
        cout << x << ' ';
    }
    cout << '\n';
    cout << (n + k - 1) / k << '\n';
    for (int i = 0; i < n; i++) {
        cout << (i + k) / k << ' ';
    }
    cout << '\n';
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
