#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    string s, t;
    cin >> n >> s >> t;

    vector dp(1 << n, vector(n + 1, -1));
    int init = 0, req = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            init |= 1 << i;
        }
        if (t[i] == 'W') {
            req |= 1 << i;
        }
    }

    dp[init][n] = 0;
    vector<array<int, 2>> q;
    q.push_back({init, n});

    while (not q.empty()) {
        auto [mask, k] = q.back();
        q.pop_back();

        bitset<15> bs(mask);

        for (int i = 0; i + 1 < k; ++i) {
            /**
             * If k = 5, n = 7
             * 10011..01
             * Deleting at i = 2 is equivalent to
             * 
             */
            // From i to k, we need to swap
            for (int j = i; j < k; j += 2) {
                
            }
        }
        for (int i = k; i + 1 < n; ++i) {

        }
    }

    return 0;
}
