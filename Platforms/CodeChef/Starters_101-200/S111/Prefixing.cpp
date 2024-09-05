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

    int mx = *max_element(a.begin(), a.end());
    set<int> s;

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        if (s.find(a[i]) == s.end()) {
            b[i] = a[i];
            s.insert(a[i]);
        } else {
            b[i] = mx;
        }
    }

    for (auto x: b) {
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
