#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int play(int a) {
    cout << a << endl;
    int b; cin >> b;
    return b;
}

void solve() {
    int n; cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int mex = 0, a, b;
    while (mex < n and s[mex] == mex) {
        mex++;
    }

    a = mex;
    for (int _ = 0; _ < 2 * n + 1; _++) {
        // We always add the mex
        b = play(a);
        if (b == -1) break;
        a = b;
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
