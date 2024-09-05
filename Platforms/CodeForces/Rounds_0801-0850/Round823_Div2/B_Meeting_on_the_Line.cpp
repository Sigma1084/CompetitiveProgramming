#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;
    vector<int> b(n); for (auto &x: b) cin >> x;

    auto mB = max_element(all(b));
    int x = a[mB - b.begin()];

    for (int i = 0; i < n; i++) {
        if (a[i] < x)
            a[i] = min(a[i] + (*mB - b[i]), x);
        else if (a[i] > x)
            a[i] = max(a[i] - (*mB - b[i]), x);
    }

    int r = *max_element(all(a)) + *min_element(all(a));
    cout << r/2 << (r%2 ? ".5" : "");
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

