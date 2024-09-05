#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<char, vector<int>> f;
    for (int i = 0; i < n; ++i) {
        f[s[i]].push_back(i);
    }

    if (abs(int(f['N'].size()) - int(f['S'].size())) % 2
            or abs(int(f['E'].size()) - int(f['W'].size())) % 2) {
        cout << "NO";
        return;
    }

    if (n == 2 and s[0] != s[1]) {
        cout << "NO";
        return;
    }

    string ans(n, ' ');

    while (f['N'].size() > f['S'].size()) {
        ans[f['N'].back()] = 'R';
        f['N'].pop_back();
        ans[f['N'].back()] = 'H';
        f['N'].pop_back();
    }
    while (f['S'].size() > f['N'].size()) {
        ans[f['S'].back()] = 'R';
        f['S'].pop_back();
        ans[f['S'].back()] = 'H';
        f['S'].pop_back();
    }
    while (f['E'].size() > f['W'].size()) {
        ans[f['E'].back()] = 'H';
        f['E'].pop_back();
        ans[f['E'].back()] = 'R';
        f['E'].pop_back();
    }
    while (f['W'].size() > f['E'].size()) {
        ans[f['W'].back()] = 'H';
        f['W'].pop_back();
        ans[f['W'].back()] = 'R';
        f['W'].pop_back();
    }

    for (int i = 0; i < int(f['N'].size()); ++i) {
        ans[f['N'][i]] = i % 2 ? 'H' : 'R';
        ans[f['S'][i]] = i % 2 ? 'H' : 'R';
    }
    for (int i = 0; i < int(f['W'].size()); ++i) {
        ans[f['W'][i]] = i % 2 ? 'R' : 'H';
        ans[f['E'][i]] = i % 2 ? 'R' : 'H';
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
