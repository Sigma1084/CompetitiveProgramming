#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * a(n-1) + bn = 1
 * a = -1 and b = 1
 * a(n-1) = 1  (mod n)
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    if (n == 1) {
        for (int i = 0; i < 3; ++i) {
            cout << "1 1\n";
            a[0] = -a[0];
            cout << a[0] << '\n';
        }
        return 0;
    }

    vector<ll> ans(n - 1);
    for (int i = 0; i+1 < n; ++i) {
        ans[i] = (a[i] % n) * (n - 1);
        a[i] += ans[i];
    }

    cout << "1 " << n - 1 << '\n';
    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << '\n';

    cout << n << ' ' << n << '\n';
    cout << -a.back() << '\n';
    a.back() = 0;

    cout << "1 " << n << '\n';
    for (auto x: a) {
        cout << -x << ' ';
    }
    cout << '\n';

    return 0;
}
