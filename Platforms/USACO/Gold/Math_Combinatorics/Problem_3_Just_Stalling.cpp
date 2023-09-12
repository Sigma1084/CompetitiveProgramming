#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    // Bitmask dp
    vector<ll> dp(1 << n);
    dp[0] = 1;  // 0 stalls
    // 11001 => No. ways to use cows 1, 2, 5 for stalls 1, 2, 3

    for (int i = 1, k; i < (1 << n); i++) {
        bitset<24> bs(i);
        k = bs.count();  // No. of stalls rn
        for (int j = 0; j < n; j++) {
            if (!bs[j]) continue;
            if (a[j] > b[k - 1]) continue;
            dp[i] += dp[i ^ (1 << j)];
        }
    }

    cout << dp.back() << '\n';

    return 0;
}
