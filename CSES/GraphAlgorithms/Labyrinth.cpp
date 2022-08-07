#include <bits/stdc++.h>
using namespace std;

void solve() {
    int r, c; cin >> r >> c; 
    vector<string> b(r); for (auto &s: b) cin >> s;
    auto exists = [&] (int i, int j) -> bool{
        return i>=0 and i<r and j>=0 and j<c;
    };

    // N E S W   OR   U R D L
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    vector<vector<char>> dir(r, vector<char>(c, '_'));
    queue<pair<int, int>> q;

    for (int i=0; i<r; i++) for (int j=0; j<c; j++)
        if (b[i][j] == 'A') { 
            q.push({i, j});
            dir[i][j] = '$';  // Indicating Start 
        }
    
    while (not q.empty()) {
        auto x = q.top();
        int i = it->first, j = it->second;
        vector<int> temp = { w[i][j] };
        if (exists(i+1, j) and b[i+1][j] == '.' or b[i+1][j] == 'B')
            q.push_back({i+1, j});
        if (exists(i-1, j) and b[i-1][j] == '.' or b[i-1][j] == 'B')
            q.push_back({i-1, j});
        if (exists(i, j+1) and b[i][j+1] == '.' or b[i][j+1] == 'B')
            q.push_back({i, j+1});
        if (exists(i, j-1) and b[i][j-1] == '.' or b[i][j-1] == 'B')
            q.push_back({i, j-1});
    }

    if (ans.empty()) cout << "NO";
    else {
        cout << "YES\n" << ans.size();
        cout << "\n" << ans;
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
