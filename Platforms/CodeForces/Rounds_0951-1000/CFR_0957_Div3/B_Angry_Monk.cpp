#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    int mx = 0, sm = 0;
    for (int i = 0; i < k; ++i) {
        int x; 
        cin >> x;

        mx = max(mx, x);
        sm += x - 1 + x;
    }

    sm -= mx - 1 + mx;

    cout << sm;
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
