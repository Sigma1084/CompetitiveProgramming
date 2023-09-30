#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();

    int ans = (n + 1) / 2;

    if (n % 2 == 1) {
        bool ok = false;
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                ok = true;
            }
        }
        if (not ok) {
            ans--;
        }
    }

    cout << ans << '\n';

    return 0;
}
