#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    auto work = [&]() {
        vector<ll> pr(n);
        pr[0] = a[0];
        for (int i = 1; i < n; ++i) {
            pr[i] = pr[i - 1] + a[i];
        }

        vector<int> nextDiff(n);
        nextDiff[n - 1] = n;
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] == a[i+1]) {
                nextDiff[i] = nextDiff[i + 1];
            } else {
                nextDiff[i] = i + 1;
            }
        }

        vector<int> ans(n, INF);
        for (int i = n - 2; i >= 0; --i) {
            // Find j such that
            // a[i+1] + ... a[j] > a[i]
            // pr[j] - pr[i] > a[i]
            // pr[j] > pr[i] + a[i]
            int j = upper_bound(pr.begin(), pr.end(), pr[i] + a[i]) - pr.begin();
            if (j < n) {
                if (i+1 != j) {
                    j = max(j, nextDiff[i+1]);
                }
                if (j < n) {
                    ans[i] = j - i;
                }
            }
        }

        return ans;
    };

    auto ans1 = work();
    reverse(a.begin(), a.end());
    auto ans2 = work();
    reverse(ans2.begin(), ans2.end());

    for (int i = 0; i < n; ++i) {
        ans1[i] = min(ans1[i], ans2[i]);
    }

    for (auto x: ans1) {
        cout << (x == INF ? -1 : x) << ' ';
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
