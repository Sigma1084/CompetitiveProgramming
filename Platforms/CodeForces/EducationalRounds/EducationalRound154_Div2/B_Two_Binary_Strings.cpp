#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string a, b;
    cin >> a >> b;

    for (int i = 0; i + 1 < a.size(); i++) {
        if (a[i] == '0' and b[i] == '0'
                and a[i + 1] == '1' and b[i + 1] == '1') {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
