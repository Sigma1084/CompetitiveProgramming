#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    // Minimum is n
    if (k < n or k % 2 != n % 2) {
        cout << "No\n";
        return 0;
    }

    bool fl = false;

    // We think of opening doors
    vector<array<int, 2>> path;
    path.reserve(k);
    for (int i = 0; i < n; i += 2) {
        int req = (k - (n - i - 2)) / 2;
        req = min(req, m);
        if (n % 2) {
            if (i == n - 1) {
                path.push_back({i, 0});
                --k;
                break;
            }
            if (i + 2 == n - 1 and k != 2 * req + 1) {
                fl = true;
                break;
            }
        }
        for (int j = 0; j < req; ++j) {
            path.push_back({i, j});
        }
        for (int j = req - 1; j >= 0; --j) {
            path.push_back({i + 1, j});
        }
        k -= 2 * req;
    }

    if (fl) {
        for (int j = 0; j < m; ++j) {
            path.push_back({n - 3, j});
        }
        k -= m;
        for (int j = m - 1; j >= 0; --j) {
            if (k != j + 2) {
                path.push_back({n - 2, j});
                path.push_back({n - 1, j});
                path.push_back({n - 1, j - 1});
                path.push_back({n - 2, j - 1});
                k -= 4;
                --j;
            } else {
                path.push_back({n - 2, j});
                --k;
            }
        }
        path.push_back({n - 1, 0});
        --k;
    }

    assert(k == 0);

    vector<string> a(2*n + 1, string(2*m + 1, '+'));
    for (int i = 1; i <= 2*n; i += 2) {
        for (int j = 1; j <= 2*m; j += 2) {
            a[i][j] = 'o';
        }
    }
    for (int i = 2; i + 2 <= 2*n; i += 2) {
        for (int j = 1; j + 1 <= 2*m; j += 2) {
            a[i][j] = '-';
        }
    }
    for (int i = 1; i + 1 <= 2*n; i += 2) {
        for (int j = 2; j + 2 <= 2*m; j += 2) {
            a[i][j] = '|';
        }
    }
    a.front()[1] = 'S';
    a.back()[1] = 'G';

    auto cr = [&](int r) {
        return 2 * r + 1;
    };
    auto cc = [&](int c) {
        return 2 * c + 1;
    };

    k = int(path.size());
    for (int i = 0; i + 1 < k; ++i) {
        auto [r1, c1] = path[i];
        auto [r2, c2] = path[i + 1];
        if (r1 == r2) {
            a[cr(r1)][cc(c1) + c2 - c1] = '.';
        } else {
            a[cr(r1) + r2 - r1][cc(c1)] = '.';
        }
    }

    cout << "Yes\n";
    for (auto &s: a) {
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }

    return 0;
}
