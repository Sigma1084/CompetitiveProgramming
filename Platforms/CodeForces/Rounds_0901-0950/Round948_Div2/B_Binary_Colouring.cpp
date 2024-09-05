#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x;
    cin >> x;

    vector<int> a(32);
    for (int i = 0; i < 32; ++i) {
        a[i] = (x >> i) & 1;
        if (i and a[i] > 0 and a[i-1] > 0) {
            a[i-1] = -1;
            a[i] = 0;
            x += 1 << (i-1);
        }
    }

    while (a.back() == 0) {
        a.pop_back();
    }

    cout << a.size() << '\n';
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ';
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
