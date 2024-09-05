#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int s = 0;
    for (auto &x: a) {
        cin >> x;
        x %= 3;
        s += x;
    }
    s %= 3;

    if (s == 0) {
        cout << 0;
    } else if (s == 2) {
        cout << 1;
    } else {
        if (count(a.begin(), a.end(), 1)) {
            cout << 1;
        } else {
            cout << 2;
        }
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
