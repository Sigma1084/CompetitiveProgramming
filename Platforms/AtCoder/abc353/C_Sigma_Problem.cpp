#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int A = 1e8;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    ll ans = 0;
    for (auto x: a) {
        ans += 1LL * (n - 1) * x;
    }

    for (int i = 0, j = n; i < n; ++i) {
        // For how many are we subtracting 1e8 for i
        if (j == i) ++j;
        while (j-1 > i and a[i] + a[j-1] >= A) {
            --j;
        }
        ans -= 1LL * (n - j) * A;
    }

    cout << ans;

    return 0;
}
