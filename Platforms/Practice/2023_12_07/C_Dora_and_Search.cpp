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

    multiset<int> ms{a.begin(), a.end()};

    for (int i = 0, j = n - 1; i < j; ) {
        if (a[i] == *ms.begin() or a[i] == *ms.rbegin()) {
            ms.erase(ms.find(a[i]));
            ++i;
        } else if (a[j] == *ms.begin() or a[j] == *ms.rbegin()) {
            ms.erase(ms.find(a[j]));
            --j;
        } else {
            cout << i + 1 << ' ' << j + 1;
            return;
        }
    }

    cout << -1;
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
