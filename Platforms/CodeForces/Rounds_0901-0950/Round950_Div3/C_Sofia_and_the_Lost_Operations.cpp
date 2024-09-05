#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }
    
    int m;
    cin >> m;

    vector<int> c(m);
    for (auto &x: c) {
        cin >> x;
    }

    if (find(b.begin(), b.end(), c.back()) == b.end()) {
        cout << "NO";
        return;
    }

    multiset<int> av(c.begin(), c.end());
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            continue;
        }
        if (av.count(b[i]) == 0) {
            cout << "NO";
            return;
        }
        av.erase(av.find(b[i]));
    }

    cout << "YES";
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
