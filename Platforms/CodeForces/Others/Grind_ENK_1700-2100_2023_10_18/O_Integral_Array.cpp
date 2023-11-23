#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, c;
    cin >> n >> c;

    vector<int> cnt(c + 1), sum(c + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int s = 0; s <= c; ++s) {
        sum[s] = sum[s-1] + cnt[s];
    }

    for (int x = 1; x <= c; ++x) {
        if (cnt[x] == 0) {
            continue;
        }
        for (int k = 1; k * x <= c; ++k) {
            // We have multiples of the form [k*x, (k+1)*x - 1]
            if (sum[min(c, (k + 1) * x - 1)] - sum[k * x - 1]) {
                if (cnt[k] == 0) {
                    cout << "No";
                    return;
                }
            }
        }
    }

    cout << "Yes";
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
