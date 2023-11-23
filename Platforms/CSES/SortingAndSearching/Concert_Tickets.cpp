#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    multiset<int, greater<>> tickets;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        tickets.insert(x);
    }

    for (int i = 0, x; i < m; ++i) {
        cin >> x;
        auto it = tickets.lower_bound(x);
        if (it == tickets.end()) {
            cout << -1 << '\n';
        } else {
            cout << *it << '\n';
            tickets.erase(it);
        }
    }

    return 0;
}
