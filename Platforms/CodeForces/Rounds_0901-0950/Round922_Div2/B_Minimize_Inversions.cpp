#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPossible(int n, const vector<int> &a, ll k) {
    /**
     * Assuming all subarrays are maxed at k
     * dp[i] := min cost to make a[0..i] valid
     *          such that a[i] is a pivot
     */
    vector<ll> dp(n + 1);
    ll sm = 0;
    multiset<ll> ms;
    ms.insert(0);
    for (int i = 0, l = 0; i <= n; ++i) {        
        // k <= sum[l...i-1]
        // l-1 is the first valid pivot
        while (l < i and sm > k) {
            sm -= a[l];
            ms.erase(ms.find(a[l]));
            ++l;
        }
        dp[i] = *ms.rbegin();
        sm += a[i];
    }
    return dp[n] <= k;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    a.push_back(0);

    ll m = *max_element(a.begin(), a.end());
    ll M = accumulate(a.begin(), a.end(), 0LL);
    while (m <= M) {
        ll mid = (m + M) / 2;
        if (isPossible(n, a, mid)) {
            M = mid - 1;
        } else {
            m = mid + 1;
        }
    }

    cout << m;
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
