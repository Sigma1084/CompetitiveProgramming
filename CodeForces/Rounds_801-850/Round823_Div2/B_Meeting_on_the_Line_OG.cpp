#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> a(n);
    for (auto &x: a) cin >> x.first;
    for (auto &x: a) cin >> x.second;

    sort(a.begin(), a.end());

    int maxTime = a[0].second, pos = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].second > maxTime) {
            maxTime = a[i].second;
            pos = i;
        }
    }

    for (int i = 0; i < pos; i++) {
        a[i].first = min(a[i].first + (maxTime - a[i].second), a[pos].first);
    }

    for (int i = pos+1; i < n; i++) {
        a[i].first = max(a[i].first - (maxTime - a[i].second), a[pos].first);
    }

    sort(a.begin(), a.end());

    cout << fixed << setprecision(10) << 1.0 * (a.front().first + a.back().first) / 2;
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

