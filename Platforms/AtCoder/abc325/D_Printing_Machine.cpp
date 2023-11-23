#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<ll, 2>> a(n);
    for (auto &[x, y]: a) {
        cin >> x >> y;
        y += x;
    }

    sort(a.begin(), a.end());

    a.push_back({ll(2e18), ll(2e18)});

    int ans = 0;
    ll t = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    // Start tasks normally
    // When a task ends, increase time by 1
    for (int i = 0; i <= n; ++i) {
        // Process all the tasks that end before i starts
        while (!pq.empty() and t < a[i][0]) {
            auto e = pq.top(); pq.pop();
            if (e < t) {
                // The task ends before the current time
                continue;
            } else {
                // This task can be noted
                t += 1;
                ans += 1;
            }
        }
        t = a[i][0];
        pq.push(a[i][1]);
    }

    cout << ans;

    return 0;
}
