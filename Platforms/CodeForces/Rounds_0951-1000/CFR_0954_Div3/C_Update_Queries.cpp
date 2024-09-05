#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> ch(n);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        --x;
        ++ch[x];
    }

    string t;
    cin >> t;
    sort(t.begin(), t.end());

    for (int i = 0, j = 0; i < n; ++i) {
        if (ch[i] > 0) {
            s[i] = t[j++];
        }
    }

    cout << s;
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
