#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    reverse(s.begin(), s.end());
    while (s.back() == '0') {
        s.pop_back();
    }
    reverse(s.begin(), s.end());
    n = s.size();

    vector<int> ans(n);
    ans[0] = s[0] - '0';
    for (int i = 1; i < n; ++i) {
        ans[i] = ans[i-1] + (s[i] - '0');
    }

    for (int i = n-1; i > 0; --i) {
        ans[i-1] += ans[i] / 10;
        ans[i] %= 10;
    }

    for (int x: ans) {
        cout << x;
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
