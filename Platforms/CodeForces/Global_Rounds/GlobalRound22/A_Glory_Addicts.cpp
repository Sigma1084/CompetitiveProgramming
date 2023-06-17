#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    vector<int> t(n); for (auto &x: t) cin >> x;

    vector<int> t1, t2;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (t[i] == 0) t1.push_back(x);
        else t2.push_back(x);
    }

    sort(all(t1));
    sort(all(t2));

    ll ans = 0;

    if (t1.size() == t2.size()) {
        ans = 2LL * accumulate(all(t1), 0LL);
        ans += 2LL * accumulate(all(t2), 0LL);
        ans -= min(t1[0], t2[0]);
    } else if (t1.size() > t2.size()) {
        // Add all the elements of t2 twice
        ans = 2LL * accumulate(all(t2), 0LL);
        // Add the last n elements of t1 twice
        ans += accumulate(t1.rbegin(), t1.rbegin() + t2.size(), 0LL);
        ans += accumulate(t1.begin(), t1.end(), 0LL);
    } else {
        swap(t1, t2);
        // Add all the elements of t2 twice
        ans = 2LL * accumulate(all(t2), 0LL);
        // Add the last n elements of t1 twice
        ans += accumulate(t1.rbegin(), t1.rbegin() + t2.size(), 0LL);
        ans += accumulate(t1.begin(), t1.end(), 0LL);
    }

    cout << ans;
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

