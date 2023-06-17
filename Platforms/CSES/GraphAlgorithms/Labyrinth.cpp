#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1e7;

void solve() {
    int r, c; cin >> r >> c; 
    vector<string> b(r); for (auto &s: b) cin >> s;
    auto exists = [&] (int i, int j) -> bool {
        return i>=0 and i<r and j>=0 and j<c;
    };

    // N E S W   OR   U R D L
    char dirs[] = {'D', 'L', 'U', 'R'};  // Reversed
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    map<char, pair<int, int>> revStr = {
        {'D', {-1, 0}},
        {'L', {0, 1}},
        {'U', {1, 0}},
        {'R', {0, -1}}
    };

    vector<vector<int>> level(r, vector<int>(c, INF));
    vector<vector<char>> dir(r, vector<char>(c, '_'));
    queue<pair<int, int>> q;
    int xFin, yFin;

    bool ok = true;
    for (int i=0; i<r and ok; i++) for (int j=0; j<c and ok; j++)
        if (b[i][j] == 'A') {
            q.push({i, j});
            level[i][j] = 0;  // Indicating Start
        } else if (b[i][j] == 'B') {
            xFin = i;
            yFin = j;
        }
    
    ok = true;
    while (!q.empty() and ok) {
        int x = q.front().first, y = q.front().second; q.pop();
        if (level[x][y] != INF and b[x][y] != 'A') continue;
        if (b[x][y] == 'B') ok = false;
        for (int d = 0; d < 4; d++) {
            int nX = x + dr[d], nY = y + dc[d];
            if (not exists(nX, nY)) continue;
            const int &newLevel = level[nX][nY];
            if (newLevel == INF and b[nX][nY] != '#') {
                q.push({x + dr[d], y + dc[d]});
            } else if (1 + newLevel < level[x][y]) {
                level[x][y] = 1 + newLevel;
                dir[x][y] = dirs[d];
            }
        }
    }
    
    // for (auto &x: level) { 
    //     for (auto &y: x) cout << y << ' ';
    //     cout << '\n';
    // }

    // for (auto &x: dir) {
    //     for (auto &y: x) cout << y << ' ';
    //     cout << '\n';
    // }

    if (ok) {
        cout << "NO";
    } else {
        string ans;
        while (b[xFin][yFin] != 'A') {
            ans += dir[xFin][yFin];
            auto diff = revStr[ans.back()];
            xFin += diff.first, yFin += diff.second;
        }
        reverse(ans.begin(), ans.end());
        cout << "YES\n" << ans.size() << '\n';
        cout << ans;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }

    return 0;
}
