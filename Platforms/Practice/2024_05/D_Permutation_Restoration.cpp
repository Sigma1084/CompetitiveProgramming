#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> b(n);
    for (auto &x: b) {
        cin >> x;
    }

    vector<array<int, 3>> lh(n);
    for (int i = 0; i < n; ++i) {
        lh[i][0] = (i + 1) / (b[i] + 1) + 1;
        lh[i][1] = b[i] == 0 ? n : (i + 1) / b[i];
        lh[i][2] = i;
    }
    sort(lh.begin(), lh.end());
    
    vector<int> a(n);
    priority_queue<array<int, 2>> pq;
    for (int i = 1, j = 0; i <= n; ++i) {
        for (; j < n and lh[j][0] == i; ++j) {
            pq.push({-lh[j][1], lh[j][2]});
        }
        if (pq.empty()) {
            cout << -1 << ' ';
        } else {
            auto [r, ind] = pq.top();
            pq.pop();
            a[ind] = i;
        }
    }

    for (auto x: a) {
        cout << x << ' ';
    }
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
