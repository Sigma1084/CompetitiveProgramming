#include <bits/stdc++.h>
using namespace std;

string s;

constexpr int N = 7;
// array<array<bool, N>, N> grid = {false};
vector<vector<bool>> grid(N, vector<bool>(N, false));
int ans = 0, cnt = 0;

inline bool isEmpty(int x, int y) {
    return 0 <= x and x < N and 0 <= y and y < N and !grid[x][y];
}

inline bool isBlocked(int x, int y) {
    return !isEmpty(x, y);
}

[[maybe_unused]]
void debug(int x, int y) {
    cerr << "x = " << x << ", y = " << y << '\n';
    cerr << "cnt = " << cnt << '\n';
    cerr << "Current grid:\n";
    for (const auto &row: grid) {
        for (const auto& col: row) {
            cerr << col << ' ';
        }
        cerr << '\n';
    }
    cerr << '\n';
}

void go(int x, int y) {
    // Final case
    if (x == 6 and y == 0) {
        ans += cnt == 48;
        return;
    } else if (cnt == 48) {
        return;
    }

    // Mark as visited
    grid[x][y] = true;
    cnt++;

    // debug(x, y);

    if (s[cnt - 1] == '?' or s[cnt - 1] == 'U') {
        if (x - 1 >= 0 and !grid[x - 1][y]) {
            // Check for split
            if (isBlocked(x - 2, y) and isEmpty(x - 1, y - 1)
                    and isEmpty(x - 1, y + 1)) {
                // Do nothing
            } else {
                go(x - 1, y);
            }
        }
    }

    if (s[cnt - 1] == '?' or s[cnt - 1] == 'D') {
        if (x + 1 < N and !grid[x + 1][y]) {
            // Check for split
            if (isBlocked(x + 2, y) and isEmpty(x + 1, y - 1)
                    and isEmpty(x + 1, y + 1)) {
                // Do nothing
            } else {
                go(x + 1, y);
            }
        }
    }

    if (s[cnt - 1] == '?' or s[cnt - 1] == 'L') {
        if (y - 1 >= 0 and !grid[x][y - 1]) {
            // Check for split
            if (isBlocked(x, y - 2) and isEmpty(x - 1, y - 1)
                    and isEmpty(x + 1, y - 1)) {
                // Do nothing
            } else {
                go(x, y - 1);
            }
        }
    }

    if (s[cnt - 1] == '?' or s[cnt - 1] == 'R') {
        if (y + 1 < N and !grid[x][y + 1]) {
            // Check for split
            if (isBlocked(x, y + 2) and isEmpty(x - 1, y + 1)
                    and isEmpty(x + 1, y + 1)) {
                // Do nothing
            } else {
                go(x, y + 1);
            }
        }
    }

    // Unmark as visited
    grid[x][y] = false;
    cnt--;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // s = string(48, '?');
    cin >> s;

    go(0, 0);

    std::cout << ans << std::endl;

    return 0;
}
