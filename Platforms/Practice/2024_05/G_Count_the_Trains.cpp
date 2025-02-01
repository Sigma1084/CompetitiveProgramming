#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    set<int> s;  // Starts
    for (int i = 0; i < n; ) {
        s.insert(i++);
        while (i < n and a[i] >= a[*s.rbegin()]) {
            ++i;
        }
    }

    while (m--) {
        int i, d;
        cin >> i >> d;
        --i;

        auto it = prev(s.upper_bound(i));

        if (a[i] - d >= a[*it]) {
            a[i] -= d;
            cout << s.size() << ' ';
            continue;
        }

        a[i] -= d;

        if (i != *it) {
            // New train starts at i
            s.insert(i);
        }

        // Now to handle merges
        it = s.upper_bound(i);
        vector<int> rem;
        while (it != s.end() and a[*it] >= a[i]) {
            rem.push_back(*it);
            it = next(it);
        }
        for (auto x: rem) {
            s.erase(x);
        }

        cout << s.size() << ' ';
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
