#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
void debug(const vector<T> &a, string name = "") {
    cerr << name << ": ";
    for (auto x: a) {
        cerr << x << ' ';
    }
    cerr << '\n';
}

vector<ll> get_dp(int n, vector<int> a) {
    for (int i = 0; i < n; ++i) {
        a[i] += n - 1 - i;
    }
    /**
     * dp[i] := {
     *    j := maximum in {0, 1, ..., i - 1} satisfying a[j] <= a[i]
     *    dp[i] = dp[j] + sum(j + 1, i - 1) - a[i] * (i - j - 1)
     * }
     */
    vector<ll> dp(n);
    stack<pair<int, int>> st;  // {value, index}
    for (int i = 0; i < n; ++i) {
        while (not st.empty() and st.top().first > a[i]) {
            st.pop();
        }
        if (st.empty()) {
            dp[i] = -1;
        } else {
            dp[i] = st.top().second;
        }
        st.emplace(a[i], i);
    }

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    for (int i = 0; i < n; ++i) {
        int j = dp[i];
        dp[i] = (j == -1 ? 0 : dp[j]);
        // a[j] <= a[i]
        // Remove the extra in [j+1, i-1]
        dp[i] += pref[i] - pref[j+1] - 1LL * a[i] * ((i-1) - (j+1) + 1);
        // If a[i] < something, then something needs to be added again
        // a[j] must be at least n - 1 - j, anything below is not possible
        // Find k such that n - 1 - k = a[i]
        int k = n - 1 - a[i];
        if (k < j or k > i) continue;
        dp[i] -= 1LL * (k - j) * (k - j - 1) / 2;
    }

    return dp;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    auto dp_left = get_dp(n, a);
    reverse(a.begin(), a.end());
    auto dp_right = get_dp(n, a);
    reverse(dp_right.begin(), dp_right.end());
    reverse(a.begin(), a.end());

    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp_left[i] + dp_right[i] + a[i]);
    }

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
