#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }

    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);

    sort(ind.begin(), ind.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    for (int i = 0; i + 1 < n; ++i) {
        if (b[ind[i]] > b[ind[i + 1]]) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
