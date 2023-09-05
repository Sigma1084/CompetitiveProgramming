#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, a, q;
    cin >> n >> a >> q;

    string s;
    cin >> s;

    int mxA = a;
    int tot = a;
    for (char c: s) {
        if (c == '+') {
            a++;
            tot++;
        } else {
            a--;
        }
        mxA = max(a, mxA);
    }

    if (mxA == n) {
        cout << "YES";
    } else if (tot >= n) {
        cout << "MAYBE";
    } else {
        cout << "NO";
    }
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
