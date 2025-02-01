#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 1e9;

bool isPossible(vector<int> a, int val, int k) {
    for (auto &x: a) {
        if (2*x < val) {
            x = val;
            --k;
        }
        if (k < 0) return false;
    }

    if (k >= 2) {
        // Can change 2 elements and done
        return true;
    }

    if (k == 1) {
        // We need 1 element >= val
        return *max_element(a.begin(), a.end()) >= val;
    }

    for (int i = 1; i < int(a.size()); ++i) {
        if (min(a[i], a[i-1]) >= val) {
            return true;
        }
    }

    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int l = 0, r = INF;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (isPossible(a, m, k)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << r;
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
