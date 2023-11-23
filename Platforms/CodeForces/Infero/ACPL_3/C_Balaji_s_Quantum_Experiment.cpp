#include <bits/stdc++.h>
using namespace std;

int ask(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    int s = ask(1, n);
    a[1] = s - ask(2, n);
    int s2 = a[1];
    for (int i = 2; i < n; ++i) {
        a[i] = ask(1, i) - s2;
        s2 += a[i];
    }
    a[n] = s - s2;

    cout << "! ";
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
    }

    return 0;
}
