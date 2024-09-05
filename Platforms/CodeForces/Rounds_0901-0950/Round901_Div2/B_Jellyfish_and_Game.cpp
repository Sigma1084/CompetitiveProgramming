#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define minEl(a) min_element(a.begin(), a.end())
#define maxEl(a) max_element(a.begin(), a.end())

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    vector<int> b(m);

    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    k = (k % 4) + 4 * (k >= 4);
    for (int i = 0; i < k; ++i) {
        if (i % 2 == 0) {
            // Alice
            if (*minEl(a) < *maxEl(b)) {
                swap(*minEl(a), *maxEl(b));
            }
        } else {
            // Bob
            if (*minEl(b) < *maxEl(a)) {
                swap(*minEl(b), *maxEl(a));
            }
        }
    }

    cout << accumulate(a.begin(), a.end(), 0LL);
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
