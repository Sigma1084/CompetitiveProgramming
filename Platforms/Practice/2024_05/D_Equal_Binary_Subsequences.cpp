#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (count(s.begin(), s.end(), '0') % 2) {
        cout << -1;
        return;
    }

    vector<int> ans;
    for (int i = 0; i < 2*n; i += 2) {
        if (s[i] == s[i+1]) continue;
        if (s[i] == '0' + int(ans.size()) % 2) {
            ans.push_back(i);
        } else {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << ' ';
    for (auto x: ans) {
        cout << x + 1 << ' ';
    }
    cout << '\n';

    for (int i = 0; i < n; ++i) {
        cout << i*2 + 1 << ' ';
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
