#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ostream &operator<<(ostream &os, const vector<int> &s) {
    os << "[";
    for (auto x: s) {
        os << x << ", ";
    }
    os << "]";
    return os;
}

constexpr int K = 19;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    a.push_back(0);

    /**
     * dp[i][0] = j
     * where j is the least index such that a[i] > a[j]
     */
    vector<array<int, K + 1>> dp(n + 1);

    a[n] = 0;
    stack<int> st{{n}};
    for (int i = n - 1; i >= 0; --i) {
        while (a[st.top()] > a[i]) {
            st.pop();
        }
        dp[i][0] = st.top();
        st.push(i);
    }
    dp[n][0] = n;

    for (int k = 1; k <= K; ++k) {
        for (int i = 0; i <= n; ++i) {
            dp[i][k] = dp[dp[i][k - 1]][k - 1];
        }
    }

    // for (int k = 0; k <= 3; ++k) {
    //     cerr << "k = " << k << ": ";
    //     for (int i = 0; i <= n; ++i) {
    //         cerr << dp[i][k] << " \n"[i == n];
    //     }
    // }

    vector<int> gr(n);
    a[n] = n + 1;
    st = stack<int>{{n}};
    for (int i = n - 1; i >= 0; --i) {
        while (a[st.top()] < a[i]) {
            st.pop();
        }
        gr[i] = st.top();
        st.push(i);
    }

    // for (int i = 0; i < n; ++i) {
    //     cerr << gr[i] << " \n"[i == n - 1];
    // }

    a[n] = 0;
    // Get the max steps such that f(j, steps) > val
    auto get = [&](int j, int val) {
        int k = 0;
        for (; k < K; ++k) {
            if (a[dp[j][k+1]] <= val) {
                break;
            }
        }
        int steps = 0;
        // k is borderline fine
        for (; k >= 0; --k) {
            if (a[dp[j][k]] > val) {
                steps += 1 << k;
                j = dp[j][k];
            }
        }
        return steps;
    };

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = gr[i];
        if (gr[i] != n) {
            ++ans;
            ans += get(j, a[i]);
        }
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
