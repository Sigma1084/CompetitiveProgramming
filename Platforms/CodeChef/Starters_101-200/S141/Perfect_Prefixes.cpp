#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
        --x;
    }

    priority_queue<int, vector<int>, greater<>> pq;
    int mex = 0, prev = 0;
    vector<int> bR(n + 1), bL(n + 1);
    for (int i = 0; i < n; ++i) {
        pq.push(a[i]);
        while (not pq.empty() and pq.top() <= mex) {
            pq.pop();
            ++mex;
        }
        if (mex == i + 1) {
            bR[i] = -1;
            ++prev;
        }
        if (i > 0 and a[i-1] >= i and mex >= i) {
            bL[i] = 1;
        }
    }

    // Extra
    int e = 0, cur = 0;
    for (int i = 0; i + 1 < n; i += 2) {
        cur += bR[i] + bL[i + 1];
        if (cur < 0) {
            cur = 0;
        }
        e = max(e, cur);
    }
    cur = 0;
    for (int i = 1; i + 1 < n; i += 2) {
        cur += bR[i] + bL[i + 1];
        if (cur < 0) {
            cur = 0;
        }
        e = max(e, cur);
    }

    cout << e + prev;
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
