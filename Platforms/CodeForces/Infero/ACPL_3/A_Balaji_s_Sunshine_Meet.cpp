#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> b(n);
    for (auto &s: b) {
        cin >> s;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (b[i][j] != 'C') {
                continue;
            }
            for (int k = j+1; k < n; ++k) {
                ans += b[i][k] == 'C';
            }
            for (int k = i+1; k < n; ++k) {
                ans += b[k][j] == 'C';
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
