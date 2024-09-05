#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &i: a) for (auto &j: i) cin >> j;

    auto opSwap = [&] (int k) -> void {
        for (int i=0; i<n; i++) swap(a[k][i], a[i][k]);
    };

    auto print = [&] () -> void {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) cout << a[i][j] << ' ';
            cout << '\n';
        }
    };

    for (int i=1; i<n; i++) {
        vector<int> x, y;
        for (int j=0; j<i; j++) {
            x.push_back(a[i][j]);
            y.push_back(a[j][i]);
        }

        // y shud be small
        bool ylesx = true;
        for (int j=0; j<i; j++) {
            if (x[j] < y[j]) ylesx = false;
        }

        if (not ylesx) opSwap(i);

        if (x == y) {
            bool xlesy = true;
            for (int j=i+1; j<n; j++) {
                if (y[j] < x[j]) xlesy = false;
            }
            if (not xlesy) opSwap(i);
        }
    }

    print();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }

    return 0;
}
