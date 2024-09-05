#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    auto l = a, r = a;
    for (int i = 1; i < n; ++i) {
        l[i] = gcd(l[i], l[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
        r[i] = gcd(r[i], r[i + 1]);
    }

    int d = 0;
    for (int i = 0; i < n; ++i) {
        int g = 0;
        if (i > 0) {
            g = gcd(g, l[i - 1]);
        }
        if (i + 1 < n) {
            g = gcd(g, r[i + 1]);
        }
        d = max(d, g);
    }

    cout << d << '\n';

    return 0;
}
