#include <bits/stdc++.h>
using namespace std;

int gp2(int x) {
    return std::__lg(x & (~(x - 1)));
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int p2 = 0;
    for (int x: a) {
        p2 += gp2(x);
    }

    priority_queue<int> pq;
    for (int i = 2; i <= n; i += 2) {
        pq.push(gp2(i));
    }

    int ans = 0;
    while (!pq.empty() and p2 < n) {
        int x = pq.top();
        pq.pop();
        p2 += x;
        ans++;
    }

    if (p2 < n) {
        ans = -1;
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
