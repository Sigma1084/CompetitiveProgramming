#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    string s;
    cin >> s;

    vector<int> sc(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        sc[i] += (s[i] == 'W') - (s[i] == 'B');
        sc[p[i]] += sc[i];
    }

    cout << count(sc.begin(), sc.end(), 0);
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
