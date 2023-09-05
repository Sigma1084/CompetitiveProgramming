#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int ans = 0;
    vector<int> a(n);

    auto eval = [&]() {
        map<int, int> m;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            m[a[i]] += 1;
            if (m.size() >= k) {
                m[a[i - k]] -= 1;
                if (m[a[i - k]] == 0) {
                    m.erase(a[i - k]);
                }
            }
            if (m.size() == k) {
                m.clear();
                ans += 1;
            }
        }
        return ans;
    };

    auto dfs = [&](auto dfs, int cur) {
        if (cur == n) {
            ans += eval();
            return;
        }
        for (int i = 0; i < k; i++) {
            a[cur] = i;
            dfs(dfs, cur + 1);
        }
    };

    dfs(dfs, 0);
    cout << ans << '\n';

    return 0;
}
