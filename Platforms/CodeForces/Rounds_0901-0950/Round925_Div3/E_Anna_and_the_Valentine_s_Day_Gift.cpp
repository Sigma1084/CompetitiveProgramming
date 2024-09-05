#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    int m1 = 0;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        m1 += s.size();
        a[i] = 0;
        while (s.size() and s.back() == '0') {
            s.pop_back();
            ++a[i];
        }
    }

    sort(a.begin(), a.end(), greater<>());
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            // Anna deleted some 0s
            m1 -= a[i];
        } else {
            // Sasha does nothing
        }
    }

    if (m1 > m) {
        cout << "Sasha";
    } else {
        cout << "Anna";
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
