#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> c(n), p(n);
    vector<vector<int>> s(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i] >> p[i];
        s[i].resize(c[i]);
        for (int &x: s[i]) cin >> x;
    }

    

    return 0;
}
