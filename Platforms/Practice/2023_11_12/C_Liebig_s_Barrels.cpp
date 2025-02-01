#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k, l;
    cin >> n >> k >> l;

    int m = n * k;
    vector<int> a(m);
    for (int &x: a) {
        cin >> x;
    }

    multiset<int> ms(a.begin(), a.end());
    int sm = *ms.begin();
    ll ans = sm;
    ms.erase(ms.begin());

    for (int i = 1; i < n; ++i) {
        auto it = ms.lower_bound(sm + l + 1);
        if (it == ms.begin()) {
            cout << 0;
            return 0;
        }
        --it;
        int sm2 = *it;
        ms.erase(it);
        for (int j = 1; j < k; ++j) {
            sm2 = min(sm2, *ms.rbegin());
            ms.erase(--ms.end());
        }
        ans += sm2;
    }

    cout << ans;

    return 0;
}
