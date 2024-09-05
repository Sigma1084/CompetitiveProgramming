#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b, l;
    cin >> a >> b >> l;

    set<int> ks;

    while (l) {
        int l1 = l;
        ks.insert(l1);
        while (l1 % b == 0) {
            l1 /= b;
            ks.insert(l1);
        }
        if (l % a) {
            break;
        }
        l /= a;
    }

    cout << ks.size();
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
