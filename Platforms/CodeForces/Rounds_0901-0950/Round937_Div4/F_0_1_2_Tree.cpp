#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int n = a + b + c;

    if (2*a + b != n - 1) {
        cout << -1;
        return;
    }

    vector<int> d(n);
    for (int i = 0, j = 1; i < n; ++i) {
        if (a) {
            d[j] = d[i] + 1;
            d[j+1] = d[i] + 1;
            j += 2;
            --a;
        } else if (b) {
            d[j] = d[i] + 1;
            ++j;
            --b;
        }
    }

    cout << *max_element(d.begin(), d.end());
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
