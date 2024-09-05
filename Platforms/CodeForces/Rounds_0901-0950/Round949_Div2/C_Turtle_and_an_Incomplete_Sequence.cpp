#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<int> places;
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            places.push_back(i);
        }
    }
    int m = int(places.size());

    if (places.empty()) {
        for (int i = 0, j = 1; i < n; ++i) {
            cout << j << ' ';
            j ^= 2;
        }
        return;
    }

    bool ok = true;
    function<void(int l, int r)> work = [&](int l, int r) {
        if (a[l] == a[r]) {
            for (int i = l + 2; i < r; i += 2) {
                a[i] = a[l];
            }
            for (int i = l + 1; i < r; i += 2) {
                a[i] = 2 * a[l];
            }
            return;
        }
        if (l + 1 == r) {
            if (a[l] / 2 == a[r] or a[r] / 2 == a[l]) {
                return;
            } else {
                ok = false;
                return;
            }
        }
        if (a[l] > a[r]) {
            a[l+1] = a[l] / 2;
            work(l + 1, r);
        } else {
            a[r-1] = a[r] / 2;
            work(l, r - 1);
        }
    };

    for (int j = 0; j + 1 < m and ok; ++j) {
        int i1 = places[j], i2 = places[j + 1];
        int x1 = __lg(a[i1]), x2 = __lg(a[i2]);
        if ((abs(x1 - x2) % 2) ^ (abs(i1 - i2) % 2)) {
            cout << -1;
            return;
        }
        work(i1, i2);
    }

    if (!ok) {
        cout << -1;
        return;
    }

    for (int i = places.front() - 1; i >= 0; --i) {
        if (a[i + 1] == 1) {
            a[i] = 2;
        } else {
            a[i] = a[i + 1] / 2;
        }
    }
    for (int i = places.back() + 1; i < n; ++i) {
        if (a[i - 1] == 1) {
            a[i] = 2;
        } else {
            a[i] = a[i - 1] / 2;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
