#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end(), greater<>());

    ll ans = 0, cur = 0;
    for (int i = 0; i < int(a.size()); ++i) {
        cerr << "Start: " << a[i] << ": " << cur << '\n';
        if (cur + a[i] < 0 and k) {
            cur += ans;
            a.pop_back();  // Play the last one
            cur = 0;
            --k;
            --i;
            continue;
        }
        cerr << "End: " << a.size() << '\n';
        ans += cur;
        cur += a[i];
    }

    cout << ans;

    return 0;
}
