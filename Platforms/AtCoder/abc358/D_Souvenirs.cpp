#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    priority_queue<int, vector<int>, greater<>> av;
    ll ans = 0;
    for (int j = n - 1, i = m - 1; i >= 0; --i) {
        while (j >= 0 and a[j] >= b[i]) {
            av.push(a[j--]);
        }
        if (av.empty() or av.top() < b[i]) {
            cout << -1;
            return 0;
        }
        ans += av.top();
        av.pop();
    }

    cout << ans;

    return 0;
}
