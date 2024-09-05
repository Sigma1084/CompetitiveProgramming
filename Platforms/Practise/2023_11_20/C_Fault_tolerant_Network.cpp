#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int nearest(const vector<ll> &v, ll x) {
    int idx = 0;
    for (size_t i = 1; i < v.size(); ++i) {
        if (abs(v[i] - x) < abs(v[idx] - x)) {
            idx = i;
        }
    }
    return idx;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }

    auto dist = [&](int i, int j) -> ll {
        if (i == -1) {
            i += n;
        }
        if (j == -1) {
            j += n;
        }
        return abs(a[i] - b[j]);
    };

    ll ans = 0;
    ans = min(dist(0, 0) + dist(-1, -1), dist(0, -1) + dist(-1, 0));

    // Case 1: Connect (0, 0)
    ll cur = dist(0, 0);
    int i = nearest(a, b[n - 1]);
    int j = nearest(b, a[n - 1]);
    cur += dist(-1, j) + dist(i, -1);
    ans = min(ans, cur);

    // Case 2: Connect (0, -1)
    cur = dist(0, -1);
    i = nearest(a, b[0]);
    j = nearest(b, a[n - 1]);
    cur += dist(-1, j) + dist(i, 0);
    ans = min(ans, cur);

    // Case 3: Connect (-1, 0)
    cur = dist(-1, 0);
    i = nearest(a, b[n - 1]);
    j = nearest(b, a[0]);
    cur += dist(0, j) + dist(i, -1);
    ans = min(ans, cur);

    // Case 4: Connect (-1, -1)
    cur = dist(-1, -1);
    i = nearest(a, b[0]);
    j = nearest(b, a[0]);
    cur += dist(0, j) + dist(i, 0);
    ans = min(ans, cur);

    // Do not connect anything
    cur = 0;
    i = nearest(a, b[0]);
    j = nearest(b, a[0]);
    cur += dist(0, j) + dist(i, 0);
    i = nearest(a, b[n - 1]);
    j = nearest(b, a[n - 1]);
    cur += dist(-1, j) + dist(i, -1);
    ans = min(ans, cur);

    cout << ans;
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
