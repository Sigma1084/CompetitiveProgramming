#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll k;
    int n;
    cin >> k >> n;

    std::array<int, 64> av;
    av.fill(0);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        int y = 0;
        while (x != 1) {
            y++;
            x /= 2;
        }
        av[y]++;
    }

    std::bitset<64> req(k);

    int ans = 0;
    for (int i = 0; i < 63; i++) {
        if (i) {
            // Pull the previous ones
            av[i] += av[i - 1] / 2;
        }
        if (!req[i]) continue;
        if (!av[i]) {
            // We need to produce
            int j = i + 1;
            while (j < 64 and av[j] == 0) j++;
            if (j == 64) {
                cout << -1;
                return;
            }
            // Pull from j
            while (j > i) {
                av[j]--;
                av[--j] += 2;
                ans += 1;
            }
        }
        av[i]--;
    }

    cout << ans;
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
