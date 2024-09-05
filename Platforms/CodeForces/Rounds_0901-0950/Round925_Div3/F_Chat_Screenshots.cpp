#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> a(k, vector<int>(n));
    for (auto &v: a) {
        for (auto &x: v) {
            cin >> x;
        }
        v[0] = 0;
        v.push_back(n + 1);
    }

    vector<int> l(n + 2, -1), r(n + 2, -1);
    r[0] = n + 1, l[n + 1] = 0;

    for (const auto &v: a) {
        for (int i = 1; i <= n; ++i) {
            if (l[v[i]] == -1) {
                // Insertion
                if (r[v[i-1]] != v[i+1] or l[v[i+1]] != v[i-1]) {
                    cout << "NO";
                    return;
                }
                l[v[i]] = v[i-1];
                r[v[i-1]] = v[i];
                r[v[i]] = v[i+1];
                l[v[i+1]] = v[i];
            } else {
                // Check only the left
                if (v[i-1] != l[v[i]]) {
                    cout << "NO";
                    return;
                }
            }
        }
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
