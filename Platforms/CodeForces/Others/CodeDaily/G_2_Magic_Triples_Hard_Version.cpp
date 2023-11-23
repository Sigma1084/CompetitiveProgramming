#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1 << 15;
vector<vector<int>> divs(N + 1);

constexpr void preCompute() {
    for (int i = 2; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            divs[j].push_back(i);
        }
    }
}

int sqPart(int x) {
    int s = 1;
    for (int v = 2; v * v * v <= x; ++v) {
        if (x % v) continue;
        int e = 0;
        while (x % v == 0) {
            x /= v;
            e++;
            if (e % 2 == 0){
                s *= v;
            }
        }
    }
    if (x > 1) {
        int u = sqrt(x);
        if (u * u == x) {
            s *= u;
        }
    }
    return s;
}

void solve() {
    int n; cin >> n;

    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    // Assume the last digit is r and look for candidates for b
    ll ans = 0;

    for (auto [x, f]: cnt) {
        ans += 1LL * f * (f - 1) * (f - 2);  // b = 1 case

        // Iterate through the divisors of square part of r
        int s = sqPart(x);
        for (auto d: divs[s]) {
            ans += 1LL * f * cnt[x / d] * cnt[x / d / d];
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    preCompute();

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
