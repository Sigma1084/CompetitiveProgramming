#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * Denote f(n, k) := Number of n-permutations with exactly k bad positions.
 * f(n, 0) = 1 (identity permutation)
 * f(n, 1) = 0
 * f(n, 2) = nC2 * !2  // Take any 2 positions and interchange them
 * f(n, 3) = nC3 * !3  // Take any 3 positions and interchange them
 * f(n, 4) = nC4 * !4  // Take any 4 positions and interchange them
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Derrangement numbers
    constexpr array<short int, 4 + 1> d = {1, 0, 1, 2, 9};

    int n, k;
    cin >> n >> k;

    ll ans = 1, comb = n;
    for (int i = 2; i <= k; i++) {
        comb = comb * (n - i + 1) / i;
        ans += comb * d[i];
    }

    cout << ans;

    return 0;
}
