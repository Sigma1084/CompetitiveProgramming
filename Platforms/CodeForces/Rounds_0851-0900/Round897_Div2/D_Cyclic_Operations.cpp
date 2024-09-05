#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] > n) {
            cout << "NO";
            return;
        }
    }

    if (k == 1) {
        for (int i = 1; i <= n; i++) {
            if (a[i] != i) {
                cout << "NO";
                return;
            }
        }
        cout << "YES";
        return;
    }

    enum State {
        UNVISITED = -1,
        CYCLE = -2
    };

    vector<int> state(n + 1, UNVISITED);

    // [UNVISITED = -1, DEPTH = d, VIS = 2 * n]
    for (int i = 1; i <= n; i++) {
        if (state[i] == CYCLE) continue;
        state[i] = 0;
        int p = i, j = a[i];

        while (state[j] == UNVISITED) {
            state[j] = state[p] + 1;
            p = j;
            j = a[j];
        }

        int cycleLen = state[p] + 1 - state[j];

        if (state[j] == CYCLE or cycleLen == k) {
            // j is a part of a k-cycle
        } else {
            cout << "NO";
            return;
        }

        state[i] = CYCLE;
        p = i; j = a[i];
        while (state[j] != CYCLE) {
            state[j] = CYCLE;
            p = j;
            j = a[j];
        }
    }

    cout << "YES";
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