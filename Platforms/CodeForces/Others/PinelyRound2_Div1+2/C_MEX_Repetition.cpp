#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<bool> isPres(n + 1);
    for (int i = 0; i < n; i++) {
        isPres[a[i]] = true;
    }
    for (int i = 0; i <= n; i++) {
        if (!isPres[i]) {
            a.push_back(i);
            break;
        }
    }

    // Cycles in MODULO n + 1
    int start = (1LL * n * k) % (n + 1);
    
    for (int i = start, j = 0; j < n; j++, start++) {
        cout << a[start % (n + 1)] << ' ';
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
