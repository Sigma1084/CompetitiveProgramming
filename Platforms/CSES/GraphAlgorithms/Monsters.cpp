#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int nR, nC; cin >> nR >> nC;
    vector<string> board(nR); for (auto &s: board) cin >> s;

    vector<vector<int>> dist(nR, vector<int>(nC, MOD));
    vector<vector<char>> info(nR, vector<char>(nC, '_'));

    // R D L U
    char dirs[] = { 'R', 'D', 'L', 'U' }; // reverse
    int dR[] = { 0, 1, 0, -1 };
    int dC[] = { 1, 0, -1, 0 };
    map<char, int> addR = {{'R', 0}, {'L', 0}, {'U', 1}, {'D', -1}};
    map<char, int> addC = {{'R', -1}, {'L', 1}, {'U', 0}, {'D', 0}};

    queue<vector<int>> q;
    for (int r = 0; r < nR; r++) for (int c = 0; c < nC; c++) {
        if (board[r][c] == 'M') {
            q.push({r, c});
            dist[r][c] = 0;
            info[r][c] = '_';
        }
    }

    for (int r = 0; r < nR; r++) for (int c = 0; c < nC; c++) {
        if (board[r][c] == 'A') {
            q.push({r, c});
            dist[r][c] = 0;
            info[r][c] = 'h';
            if (r == 0 or r == nR-1 or c == 0 or c == nC-1) {
                cout << "YES\n0";
                return;
            }
        }
    }

    int r, c, r1, c1;
    int fR = -1, fC = -1;

    // Q insertions
    while (not q.empty() and fR == -1) {
        r = q.front()[0]; c = q.front()[1];
        q.pop();

        for (int d = 0; d < 4; d++) {
            r1 = r + dR[d]; c1 = c + dC[d];
            if (r1 < 0 or r1 >= nR or c1 < 0 or c1 >= nC) continue;
            // r1, c1 is valid
            if (board[r1][c1] == '#' or dist[r1][c1] != MOD) continue;
            dist[r1][c1] = dist[r][c] + 1;
            if (info[r][c] != '_') { 
                info[r1][c1] = dirs[d];
                if (r1 == 0 or r1 == nR-1 or c1 == 0 or c1 == nC-1) {
                    fR = r1, fC = c1;
                    break;
                }
            }
            q.push({r1, c1});
        }
    }

    if (fR == -1) {
        cout << "NO";
    } else {
        cout << "YES\n" << dist[fR][fC] << '\n';
        string ans;
        while (board[fR][fC] != 'A') {
            ans += info[fR][fC];
            char d = info[fR][fC];
            fR += addR[d]; fC += addC[d];
        }
        reverse(ans.begin(), ans.end());
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

