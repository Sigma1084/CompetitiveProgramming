#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        s[i] ^= ('0' ^ '1') * (k & 1);
    }

    vector<int> a(n);
    for (int i = 0; i < n and k; ++i) {
        if (s[i] == '0') {
            s[i] = '1';
            a[i] = 1;
            --k;
        }
    }
    s[n - 1] ^= ('0' ^ '1') * (k & 1);
    a[n - 1] += k;

    cout << s << '\n';
    for (int x: a) {
        cout << x << ' ';
    }
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
