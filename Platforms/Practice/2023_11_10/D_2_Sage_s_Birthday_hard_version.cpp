#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    priority_queue<int> pq{a.begin(), a.end()};
    vector<int> b(n);
    for (int i = 1 ^ (n & 1); i < n; i += 2) {
        b[i] = pq.top();
        pq.pop();
    }
    for (int i = (n & 1); i < n; i += 2) {
        b[i] = pq.top();
        pq.pop();
    }

    int ans = 0;
    for (int i = 1; i + 1 < n; ++i) {
        if (b[i-1] > b[i] and b[i] < b[i+1]) {
            ++ans;
        }
    }

    cout << ans << '\n';
    for (auto x: b) {
        cout << x << ' ';
    }

    return 0;
}
