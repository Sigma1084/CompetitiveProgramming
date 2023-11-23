#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    deque<int> a(n), b(n);
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;

    auto op = [&] () {
        int x = a.front(); a.pop_front();
        int y = b.front(); b.pop_front();
        a.push_back(y);
        b.push_back(x);
    };

    // Odd case, we need to find one equal element and apply operations
    int eq = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            if (eq != -1) {
                cout << -1;
                return;
            }
            eq = i;
        }
    }
    if (n % 2 == 1 and eq == -1) {
        cout << -1;
        return;
    } else if (n % 2 == 0 and eq != -1) {
        cout << -1;
        return;
    }

    // eq is the element that is supposed to be at n / 2
    if (n % 2 == 0) {
        // Product eq
        eq = n;
        int sign = a[0] > b[0] ? 1 : -1;
        for (int i = 1; i < n; ++i) {
            if (a[i] > b[i] and sign == 1) continue;
            if (a[i] < b[i] and sign == -1) continue;
            eq = i;
            break;
        }
        for (int i = eq + 1; i < n; ++i) {
            if (a[i] > b[i] and sign == -1) continue;
            if (a[i] < b[i] and sign == 1) continue;
            cout << -1;
            return;
        }
    }

    // eq must be at n / 2
    int k = n / 2;

    int t = 0;
    while (eq != k) {
        op();
        ++t;
        eq = (eq + n - 1) % n;
    }

    if (a[0] > b[0]) {
        t += n;
    }

    reverse(a.begin(), a.end());
    if (a == b) {
        cout << t;
    } else {
        cout << -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("meta_game_input.txt", "r", stdin);
    // freopen("meta_game_output.txt", "w", stdout);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }

    return 0;
}
