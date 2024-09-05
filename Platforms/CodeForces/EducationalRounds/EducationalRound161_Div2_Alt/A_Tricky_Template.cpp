#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string a, b, c;
    cin >> a >> b >> c;

    bool ok = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            if (a[i] != c[i]) {
                ok = true;
                break;
            }
        } else if (a[i] != c[i] and b[i] != c[i]) {
            ok = true;
            break;
        }
    }

    cout << (ok ? "YES" : "NO");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
