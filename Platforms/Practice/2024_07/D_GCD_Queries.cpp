#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;

    int i = 1, j = 2;
    for (int k = 3; k <= n; ++k) {
        int l = ask(i, k), r = ask(j, k);
        if (l < r) {
            i = k;
        } else if (l > r) {
            j = k;
        }
    }
    cout << "! " << i << ' ' << j << endl;

    cin >> n;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
    }

    return 0;
}
