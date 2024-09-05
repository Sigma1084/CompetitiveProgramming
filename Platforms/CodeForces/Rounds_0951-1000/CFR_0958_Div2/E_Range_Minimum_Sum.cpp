#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = 1;
    }

    vector<int> l(n, -1), r(n, n);
    vector<vector<int>> depL(n), depR(n);
    vector<pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
        while (not st.empty() and st.back().first > a[i][0]) {
            st.pop_back();
        }
        if (not st.empty()) {
            l[i] = st.back().second;
            depL[l[i]].push_back(i);
        }
        st.emplace_back(a[i][0], i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (not st.empty() and st.back().first > a[i][0]) {
            st.pop_back();
        }
        if (not st.empty()) {
            r[i] = st.back().second;
            depR[r[i]].push_back(i);
        }
        st.emplace_back(a[i][0], i);
    }

    vector<int> l2(n, -1), r2(n, n);
    st.clear();
    for (int i = 0; i < n; ++i) {
        for (int j: depL[i]) {
            if (not st.empty() and st[0].first < a[j][0]) {
                l2[j] = prev(lower_bound(st.begin(), st.end(), make_pair(a[j][0], 0)))->second;
            }
        }
        while (not st.empty() and st.back().first > a[i][0]) {
            st.pop_back();
        }
        st.emplace_back(a[i][0], i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        for (int j: depR[i]) {
            if (not st.empty() and st[0].first < a[j][0]) {
                r2[j] = prev(lower_bound(st.begin(), st.end(), make_pair(a[j][0], 0)))->second;
            }
        }
        while (not st.empty() and st.back().first > a[i][0]) {
            st.pop_back();
        }
        st.emplace_back(a[i][0], i);
    }

    vector<ll> dp(n + 1);
    auto add = [&](int l, int r, ll val) {
        dp[l] += val;
        dp[r + 1] -= val;
    };

    for (int i = 0; i < n; ++i) {
        if (l[i] >= 1) {
            add(0, l[i] - 1, 1LL * a[i][0] * (i - l[i]) * (r[i] - i));
        }
        if (l[i] >= 0) {
            add(l[i], l[i], 1LL * a[i][0] * (i - l2[i] - 1) * (r[i] - i));
        }
        if (l[i] + 1 < i) {
            add(l[i] + 1, i - 1, 1LL * a[i][0] * (i - l[i] - 1) * (r[i] - i));
        }
        if (i + 1 < r[i]) {
            add(i + 1, r[i] - 1, 1LL * a[i][0] * (i - l[i]) * (r[i] - i - 1));
        }
        if (r[i] < n) {
            add(r[i], r[i], 1LL * a[i][0] * (i - l[i]) * (r2[i] - i - 1));
        }
        if (r[i] + 1 < n) {
            add(r[i] + 1, n - 1, 1LL * a[i][0] * (i - l[i]) * (r[i] - i));
        }
    }

    for (int i = 1; i <= n; ++i) {
        dp[i] += dp[i - 1];
    }
    assert(dp[n] == 0);
    dp.pop_back();

    for (auto x: dp) {
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
