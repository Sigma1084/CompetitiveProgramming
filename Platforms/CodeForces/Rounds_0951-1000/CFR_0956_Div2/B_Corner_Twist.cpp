#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> sr(n), sc(m);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            sr[i] += s[j] - '0';
            sc[j] += s[j] - '0';
        }
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            sr[i] -= s[j] - '0';
            sc[j] -= s[j] - '0';
        
        }
    }

    for (auto x: sr) {
        if (x % 3) {
            cout << "NO";
            return;
        }
    }
    for (auto x: sc) {
        if (x % 3) {
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

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
