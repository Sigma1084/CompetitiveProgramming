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

    for (int i = 0; i < n; ++i) {
        if (is_sorted(a.begin(), a.end())) {
            cout << "Yes";
            return;
        } else {
            rotate(a.begin(), a.begin() + 1, a.end());
        }
    }

    cout << "No";
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
