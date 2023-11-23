#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector b(n, vector(m, 0));
    for (auto &row : b) {
        for (auto &x : row) {
            cin >> x;
        }
    }

    using Index = pair<int, int>;
    constexpr array<Index, 4> dd = {{{0, 0}, {0, 1}, {1, 0}, {1, 1}}};
    constexpr array<Index, 8> allDirs = {{{-1, -1}, {-1, 0}, {-1, 1},
                                        {0, -1},          {0, 1},
                                        {1, -1},  {1, 0}, {1, 1}}};
    
    // Edge First ordering
    constexpr array<Index, 8> dirs = {{
        {-1, 0}, {0, -1}, {0, 1}, {1, 0},
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    }};

    constexpr int OK = 0;

    auto isValid = [&](int i, int j) {
        return 0 <= i and i + 1 < n and 0 <= j and j + 1 < m;
    };

    auto isOk = [&](int i, int j) -> int {
        int c = OK;
        for (auto [di, dj]: dd) {
            if (b[i + di][j + dj] == OK) {
                // Do nothing
            } else if (c == OK) {
                c = b[i + di][j + dj];
            } else if (c != b[i + di][j + dj]) {
                return -1;  // Not possible
            }
        }
        return c;
    };

    using Ans = tuple<int, int, int>;
    vector<Ans> ans;
    ans.reserve(n * m);

    queue<Index> q;
    vector<vector<bool>> vis(n - 1, vector<bool>(m - 1));

    auto debug = [&] () {
        cerr << "Board:\n";
        for (auto &row : b) {
            for (auto &x : row) {
                cerr << x << ' ';
            }
            cerr << '\n';
        }
        cerr << '\n';
    };

    auto color = [&](int i, int j, int c) {
        vis[i][j] = true;
        q.emplace(i, j);
        if (c == OK) {
            return;
        }
        ans.emplace_back(i + 1, j + 1, c);
        for (auto [di, dj]: dd) {
            b[i + di][j + dj] = OK;
        }
        // debug();
    };

    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            int c = isOk(i, j);
            if (c > OK) {
                color(i, j, c);
            }
        }
    }

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (auto [di, dj]: dirs) {
            if (not isValid(i + di, j + dj)) continue;
            if (vis[i + di][j + dj]) continue;
            int c = isOk(i + di, j + dj);
            if (c == -1) continue;
            color(i + di, j + dj, c);
        }
    }

    bool ok = true;
    for (auto &row : b) {
        for (auto &x : row) {
            if (x != OK) {
                ok = false;
            }
        }
    }

    if (ok) {
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (auto [i, j, c] : ans) {
            cout << i << ' ' << j << ' ' << c << '\n';
        }
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
