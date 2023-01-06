#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k; k--;
    vector<int> a(n); for (auto &i: a) cin >> i;

    stack<array<ll, 2>> l, r;  // [treshold, gain]
    
    for (int i = 0; i < k; i++) {
        l.push({min(0, a[i]), a[i]});
        while (l.size() > 1 and l.top()[1] <= 0) {
            auto [t, g] = l.top(); l.pop();
            l.top()[0] = min(t, g + l.top()[0]);
            l.top()[1] += g;
        }
    }

    for (int i = n-1; i > k; i--) {
        r.push({min(0, a[i]), a[i]});
        while (r.size() > 1 and r.top()[1] <= 0) {
            auto [t, g] = r.top(); r.pop();
            r.top()[0] = min(t, g + r.top()[0]);
            r.top()[1] += g;
        }
    }

    ll cur = a[k];
    while (!l.empty() and !r.empty()) {
        if (cur + l.top()[0] >= 0) {
            cur += l.top()[1];
            l.pop();
        } else if (cur + r.top()[0] >= 0) {
            cur += r.top()[1];
            r.pop();
        } else {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

