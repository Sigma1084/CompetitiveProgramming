#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int ans = 0;
    for (int i = 0; i < n; ) {
        int cur = 0;
        for (; i < n and a[i] + cur <= k; ++i) {
            cur += a[i];
        }
        ++ans;
    }

    cout << ans;

    return 0;
}
