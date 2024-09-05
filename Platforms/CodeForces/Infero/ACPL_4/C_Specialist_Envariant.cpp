#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
        --x;
    }

    vector<int> f(k);
    vector<bool> vis(1000);
    for (auto x: a) {
        if (not vis[x]) {
            ++f[x % k];
            vis[x] = true;
        }
    }

    int pos = 0;
    for (int i = 1; i < k; ++i) {
        if (f[i] > f[pos]) {
            pos = i;
        }
    }

    // Make sure all students go to the position pos
    vis.assign(1000, false);
    vector<bool> taken(n);
    for (int i = 0; i < n; ++i) {
        if (not vis[a[i]] and a[i] % k == pos) {
            taken[i] = true;
            vis[a[i]] = true;
        }
    }

    cout << n - f[pos] << '\n';
    for (int i = 0, j = 0; i < n; ++i) {
        if (taken[i]) {
            continue;
        }
        // To go is j*k + pos
        while (j*k + pos < 1000 and vis[j*k + pos]) {
            ++j;
        }
        if (j*k + pos < a[i]) {
            cout << "- " << i + 1 << ' ' << (a[i] - j*k - pos) << '\n';
        } else {
            cout << "+ " << i + 1 << ' ' << (j*k + pos - a[i]) << '\n';
        }
    }

    return 0;
}
