#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * 1 -> 1
 * 2 -> 2
 * 3 -> 3
 * 4 -> 3
 * 5 -> 4
 * 6 -> 4
 * 7 -> 5
 * 8 -> 5
 * 
 * 
 * 2, 5 -> 3
 * 2, 6 -> 3
 */
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    ll cur = 0, ans = 0;
    for (int i = 0, j = n - 1; i <= j; ) {
        if (i == j) {
            // We already have cur
            if (a[i] == 1 or cur >= a[i]) {
                ans += 1;
            } else if (a[i] == 2) {
                ans += 2;
            } else {
                // a[i] >= 3
                // Make cur near a[i] / 2 and add it
                ans += (a[i] - cur + 1) / 2 + 1;
            }
            break;
        } else if (a[i] + cur < a[j]) {
            cur += a[i];
            ans += a[i];
            i++;
        } else {
            ans += a[j] - cur + 1;
            a[i] -= a[j] - cur;
            cur = 0;
            j--;
            if (a[i] == 0) i++;
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
