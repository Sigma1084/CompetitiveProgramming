#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[--a[i]] = i;
    }

    int ans = 1;
    for (int i = 0; i + 1 < n; ++i) {
        ans += pos[i] > pos[i + 1];
    }

    for (int l, r; m--; ) {
        cin >> l >> r;
        --l, --r;

        // Positions at a and b are swapped.
        set s = {a[l] - 1, a[l], a[r] - 1, a[r]};
        s.erase(-1);
        s.erase(n - 1);

        for (int i: s) {
            ans -= pos[i] > pos[i + 1];
        }

        swap(a[l], a[r]);
        swap(pos[a[l]], pos[a[r]]);

        for (int i: s) {
            ans += pos[i] > pos[i + 1];
        }

        cout << ans << '\n';
    }

    return 0;
}
