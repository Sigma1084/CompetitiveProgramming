#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;

    if (n == 1) { cout << 0; return; }

    int ans = a.back() - a.front();

    for (int i = 0; i+1 < n; i++)
        ans = max(ans, a[i] - a[i+1]);

    ans = max(ans, a.back() - *min_element(a.begin(), a.end() - 1));
    ans = max(ans, *max_element(a.begin() + 1, a.end()) - a.front());

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

