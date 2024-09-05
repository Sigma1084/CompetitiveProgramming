#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    array<int, 26> a{};
    for (char c: s) {
        ++a[c - 'a'];
    }

    int odds = 0;
    for (int x: a) {
        odds += x & 1;
    }

    if (odds - 1 <= k) {
        cout << "YES";
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
