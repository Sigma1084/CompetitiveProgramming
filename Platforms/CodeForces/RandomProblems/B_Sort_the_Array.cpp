#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    int mn = -1, mx = -1;
    for (int i = 0; i < n; ++i) {
        int idx = ord[i];
        if (idx != i) {
            mx = max(mx, i);
            if (mn == -1) {
                mn = i;
            }
        }
    }

    if (mn == -1) {
        mn = 0, mx = 0;
    }

    reverse(a.begin() + mn, a.begin() + mx + 1);

    if (is_sorted(a.begin(), a.end())) {
        cout << "yes\n" << mn + 1 << ' ' << mx + 1;
    } else {
        cout << "no";
    }

    return 0;
}
