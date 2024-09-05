#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int ext = 0, req = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1' and b[i] == '0') {
            ++ext;
        } else if (a[i] == '0' and b[i] == '1') {
            ++req;
        }
    }

    cout << max(ext, req);
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
