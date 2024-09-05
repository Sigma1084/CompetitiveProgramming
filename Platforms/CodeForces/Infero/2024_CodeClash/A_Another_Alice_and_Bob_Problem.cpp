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

    array<ll, 2> s = {0, 0};
    for (int i = 0, j = 1, k = 0; i < n or j < n; k ^= 1, ++j) {
        if (j == n or a[i] > a[j]) {
            s[k] += a[i];
            i = j;
        } else {
            s[k] += a[j];
        }
    }

    if (s[0] > s[1]) {
        cout << "ALICE";
    } else if (s[0] < s[1]) {
        cout << "BOB";
    } else {
        cout << "DRAW";
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
