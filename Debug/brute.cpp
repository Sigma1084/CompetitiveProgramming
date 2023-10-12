#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, nQ;
    cin >> n >> nQ;

    string str;
    cin >> str;

    for (int t, l, r, x; nQ--; ) {
        cin >> t >> l >> r;
        if (t == 1) {
            cin >> x;
            x %= 26;
            for (int i = l - 1; i <= r - 1; ++i) {
                str[i] = (str[i] - 'a' + x) % 26 + 'a';
            }
        } else if (t == 2) {
            bool ok = true;
            for (int i = l - 1; i <= r - 1; ++i) {
                if (i + 1 < r) {
                    if (str[i] == str[i + 1]) {
                        ok = false;
                        break;
                    }
                }
                if (i + 2 < r) {
                    if (str[i] == str[i + 2]) {
                        ok = false;
                        break;
                    }
                }
            }
            cout << (ok ? "YES" : "NO") << '\n';
        } else {
            assert(false);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::freopen("input.txt", "r", stdin);
    std::freopen("output_brute.txt", "w", stdout);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
