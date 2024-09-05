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

    int j = n - 1;
    while (j > 0 and a[j-1] <= a[j]) {
        j--;
    }

    // a[j] onwards is sorted
    for (int i = 0; i + 1 < j; ++i) {
        if (a[i] <= a[j]) {
            cout << -1;
            return;
        }
    }

    cout << j;
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
