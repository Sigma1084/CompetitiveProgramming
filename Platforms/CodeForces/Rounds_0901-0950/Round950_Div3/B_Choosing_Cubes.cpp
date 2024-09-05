#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, ind, k;
    cin >> n >> ind >> k;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
        x = -x;
    }
    int x = a[ind - 1];

    sort(a.begin(), a.end());
    int l = lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    int r = upper_bound(a.begin(), a.end(), x) - a.begin();

    if (r <= k) {
        cout << "YES";
    } else if (l <= k) {
        cout << "MAYBE";
    } else {
        cout << "NO";
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
