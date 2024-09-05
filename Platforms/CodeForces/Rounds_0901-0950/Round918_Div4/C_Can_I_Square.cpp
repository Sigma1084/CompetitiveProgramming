#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    ll s = accumulate(a.begin(), a.end(), 0LL);

    // Check if perfect square
    ll r = sqrt(s);
    if (r * r == s) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return;

    for (int x = r - 1; x <= r + 1; x++) {
        if (x * x == s) {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
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
