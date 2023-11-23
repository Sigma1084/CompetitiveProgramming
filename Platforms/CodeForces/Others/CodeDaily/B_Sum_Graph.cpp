#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int u, int v = -1) {
    if (v == -1) {
        cout << "+ " << u << endl;
    } else {
        cout << "? " << u + 1 << ' ' << v + 1 << endl;
    }
    int x;
    cin >> x;

    return x;
}

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0, v = 1; i < n; i += 2, ++v) {
        p[i] = v;
    }
    for (int i = 1, v = n; i < n; i += 2, --v) {
        p[i] = v;
    }

    ask(n + 1);
    ask(n + 2);

    vector<int> a(n), b(n);
    int s = 0, d = 0;
    for (int i = 1; i < n; ++i) {
        int di = ask(0, i);
        if (di > d) {
            d = di;
            s = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        int x = 0;
        if (i != s) {
            x = ask(s, i);
        }
        a[i] = p[x];
        b[i] = p[n - x - 1];
    }

    cout << "! ";
    for (auto x: a) {
        cout << x << ' ';
    }
    for (auto x: b) {
        cout << x << ' ';
    }
    cout << endl;

    int x;
    cin >> x;
    assert(x == 1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
