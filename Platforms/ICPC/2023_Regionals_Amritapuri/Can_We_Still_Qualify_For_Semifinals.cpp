#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr array<array<int, 2>, 45> getMatches() {
    array<array<int, 2>, 45> matches{};
    array<int, 10> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0, j = 0; i < 9; ++i) {
        for (int k = 0; k < 5; ++k) {
            matches[j++] = {a[k], a[9-k]};
        }
        for (int i = 9; i >= 2; --i) {
            a[i] = a[i] + a[i-1];
            a[i-1] = a[i] - a[i-1];
            a[i] = a[i] - a[i-1];
        }
    }
    return matches;
}
constexpr auto matches = getMatches();

int n;
array<int, 10> sc;

bool isPossible() {
    if (n == 45) {
        int k = 0;
        for (auto x: sc) {
            k += (x > sc[0]);
        }
        return k <= 3;
    }
    auto [t1, t2] = matches[n];

    sc[t1]++;
    ++n;
    bool res = isPossible();
    --n;
    sc[t1]--;

    if (res or t1 == 0) {
        return res;
    }

    sc[t2]++;
    ++n;
    res = isPossible();
    --n;
    sc[t2]--;

    return res;
}

void solve() {
    cin >> n;
    fill(sc.begin(), sc.end(), 0);

    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        auto [t1, t2] = matches[i];
        if (s[i] == '1') {
            ++sc[t1];
        } else {
            ++sc[t2];
        }
    }

    if (n < 25) {
        cout << "YES";
    } else {
        cout << (isPossible() ? "YES" : "NO");
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
