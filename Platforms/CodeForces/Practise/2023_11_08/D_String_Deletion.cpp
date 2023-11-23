#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> r = {1};
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            r.back() += 1;
        } else {
            r.push_back(1);
        }
    }

    int ans = 0;
    n = r.size();
    for (int i = 0, j = 0; i < n; ++i) {
        j = max(j, i);
        while (j < n and r[j] == 1) {
            j += 1;
        }
        if (j < n and r[j] > 1) {
            r[j] -= 1;
        } else {
            i += 1;
        }
        ans += 1;
    }

    cout << ans;
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
