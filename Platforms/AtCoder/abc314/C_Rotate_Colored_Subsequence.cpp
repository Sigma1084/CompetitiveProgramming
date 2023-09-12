#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> c(n);
    for (auto &x: c) cin >> x;

    vector<string> a(m);
    for (int i = 0; i < n; i++) {
        a[c[i] - 1].push_back(s[i]);
    }

    for (auto &x: a) {
        std::rotate(x.begin(), x.end() - 1, x.end());
        std::reverse(x.begin(), x.end());
    }

    for (int i = 0; i < n; i++) {
        cout << a[c[i] - 1].back();
        a[c[i] - 1].pop_back();
    }

    return 0;
}
