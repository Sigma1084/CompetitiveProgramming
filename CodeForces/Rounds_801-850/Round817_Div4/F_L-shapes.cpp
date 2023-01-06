#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

int n, m;
vector<string> a;
vector<vector<bool>> vis;
bool ans;

inline bool valid(int i, int j) {
    return i >= 0 and j >= 0 and i < n and j < m;
}

inline bool isRock(int x, int y) {
    return valid(x, y) and a[x][y] == '*';
}

inline int surRocks(int x, int y) {
    int ans = 0;
    for (int i = -1; i <= 1; i++) for (int j = -1; j <= 1; j++) {
        if (isRock(x+i, y+j)) ans++;
    }
    return ans;
}

inline bool touch(pair<int, int> a, pair<int, int> b) {
    return a.first == b.first or a.second == b.second;
}

inline void checkSurr(int x, int b) {
    for (int i = -1; i <= 1; i++) for (int j = -1; j <= 1; j++) {
        if (!valid(x+i, b+j)) continue;
        if (vis[x+1][b+j]) continue;
        if (a[x+i][b+j] == '*') { ans = false; return; } 
    }
}

inline void processRock(int i, int j) {

    vector<pair<int, int>> c;

    for (int x = -1; x <= 1; x++) for (int y = -1; y <= 1; y++) {
        if (x == 0 and y == 0) continue;
        if (isRock(i+x, j+y)) c.push_back({i+x, j+y});
    }
    sort(c.begin(), c.end());

    if (c.size() != 2) {
        ans = false;
        return;
    }

    if (touch(c[0], c[1])) {}
    else {
        if (c[0] == make_pair(i-1, j) and c[1] == make_pair(i, j-1)) {}
        else if (c[0] == make_pair(i-1, j) and c[1] == make_pair(i, j+1)) {}
        else if (c[0] == make_pair(i, j-1) and c[1] == make_pair(i+1, j)) {}
        else if (c[0] == make_pair(i, j+1) and c[1] == make_pair(i+1, j)) {}
        else { ans = false; return; }
    }

    for (auto &[a, b]: c) {
        if (surRocks(a, b) != 3) {
            ans = false;
            return;
        }
    }

    for (int i = 0; i < 2; i++)
        vis[c[i].first][c[i].second] = true;
}

void solve() {
    cin >> n >> m;
    ans = true;
    a.resize(n, ""); for (auto &s: a) cin >> s;
    vis.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n and ans; i++) for (int j = 0; j < m and ans; j++) {
        if (vis[i][j]) continue;
        if (a[i][j] == '*') processRock(i, j);
    }

    cout << (ans ? "YES" : "NO");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

