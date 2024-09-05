#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isVow(char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<string> ans;
    for (int i = n - 1; i >= 0; --i) {
        if (isVow(s[i])) {
            assert(not isVow(s[i - 1]));
            ans.push_back(s.substr(i - 1, 2));
            --i;
        } else {
            assert(isVow(s[i - 1]));
            assert(not isVow(s[i - 2]));
            ans.push_back(s.substr(i - 2, 3));
            i -= 2;
        }
    }

    reverse(ans.begin(), ans.end());
    n = ans.size();
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
        if (i != n - 1) {
            cout << '.';
        }
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
