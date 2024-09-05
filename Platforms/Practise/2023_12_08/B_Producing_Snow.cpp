#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n), t(n);
    for (auto &x: v) {
        cin >> x;
    }
    for (auto &x: t) {
        cin >> x;
    }

    priority_queue<ll, vector<ll>, greater<>> pq;
    ll cur = 0;
    vector<ll> ans(n);
    for (int i = 0; i < n; ++i) {
        pq.push(cur + v[i]);
        cur += t[i];
        while (!pq.empty() and pq.top() <= cur) {
            ans[i] += t[i] - (cur - pq.top());
            pq.pop();
        }
        ans[i] += pq.size() * t[i];
    }

    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
