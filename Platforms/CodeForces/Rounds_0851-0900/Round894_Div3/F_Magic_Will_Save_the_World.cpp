#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'000;

/**
 * Max mana to be used is 10^6
 * Will be over within 10^6 in any case
 * 
 * The subsets can have at most 10^6 numbers
 * 
 * At time t, we will have (wt, ft)
 * We need (w + f)t >= sum of all
 */
void solve() {
    int w, f, n; cin >> w >> f >> n;

    w = min(w, N);
    f = min(f, N);

    vector<int> a(n);
    for (int &x: a) cin >> x;
    sort(a.begin(), a.end());
    int s = accumulate(a.begin(), a.end(), 0);

    bitset<N + 1> dp{};
    dp[0] = 1;

    for (int x: a) {
        dp |= dp << x;
    }

    int ans = N + 1;
    for (int i = 0; i <= s; i++) {
        if (dp[i]) {
            ans = min(ans, max((i + w - 1) / w, (s - i + f - 1) / f));
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        solve(); cout << '\n';
    }

    return 0;
}
