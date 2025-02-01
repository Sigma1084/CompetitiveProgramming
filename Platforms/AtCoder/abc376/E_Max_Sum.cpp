#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<array<int, 2>> a(n);
    for (auto &[x, _]: a) {
        cin >> x;
    }
    for (auto &[_, y]: a) {
        cin >> y;
    }

    sort(a.begin(), a.end());
    priority_queue<int> pq;
    ll sm = 0;
    for (int i = 0; i < k; ++i) {
        sm += a[i][1];
        pq.push(a[i][1]);
    }

    ll ans = sm * a[k-1][0];
    for (int i = k; i < n; ++i) {
        sm += a[i][1];
        pq.push(a[i][1]);
        sm -= pq.top();
        pq.pop();

        ans = min(ans, sm * a[i][0]);
    }

    cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
