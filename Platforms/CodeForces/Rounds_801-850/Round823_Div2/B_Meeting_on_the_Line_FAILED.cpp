#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

pair<double, double> calc(double x1, double x2, double t1, double t2) {
    double d = x2 - x1;
    if (abs(t1 - t2) < 1e-9) {
        return { (t1 + t2)/2, (x1 + x2)/2 };
    }
    if (t1 < t2) {
        if (t1 + d <= t2) {
            return {t2, x2};
        } else {
            return {t1 + (d+t2-t1)/2, x1 + (d+t2-t1)/2 };
        }
    } else {
        if (t2 + d <= t1) {
            return {t1, x1};
        } else {
            return {t1 + (d-t2+t1)/2, x1 + (d-t2+t1)/2 };
        }
    }
}

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> a(n);
    for (auto &x: a) cin >> x.first;
    for (auto &x: a) cin >> x.second;

    sort(a.begin(), a.end());

    vector<ll> dp1(n);
    vector<ll> dp2(n); 

    dp1[0] = a[0].second;
    for (int i = 1; i < n; i++) {
        dp1[i] = max(dp1[i-1] + a[i].first - a[i-1].first, (ll)a[i].second);
    }

    dp2[n-1] = a[n-1].second;
    for (int i = n-2; i >= 0; i--) {
        dp2[i] = max(dp2[i+1] + a[i+1].first - a[i].first, (ll)a[i].second);
    }

    double ans = 1e15;
    double pos = a[0].first;

    for (int i = 0; i + 1 < n; i++) {
        auto [A, p] = calc(a[i].first, a[i+1].first, dp1[i], dp2[i+1]);
        if (A < ans) {
            ans = A;
            pos = p;
        }
    }

    cout << fixed << setprecision(12) << pos;
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

