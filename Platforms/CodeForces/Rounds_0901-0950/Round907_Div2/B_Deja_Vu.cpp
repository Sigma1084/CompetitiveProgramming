#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, nQ;
    cin >> n >> nQ;

    vector<int> a(n), q(nQ);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: q) {
        cin >> x;
    }

    constexpr int N = 30;
    array<int, N + 1> val;
    val.fill(0);
    for (int x: q) {
        for (int i = x; i <= 30; ++i) {
            if (val[i] % (1 << x) == 0) {
                val[i] += 1 << (x-1);
            } else {
                break;
            }
        }
    }

    for (auto x: a) {
        cout << x + val[__lg(x & -x)] << ' ';
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
