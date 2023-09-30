#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int n = 8;
    bitset<n> col;
    bitset<2*n - 1> diag1;  // [i + j]
    bitset<2*n - 1> diag2;  // [n - 1 - i + j]
    int ans = 0;

    vector<string> board(n);
    for (auto& row : board) {
        cin >> row;
    }

    function<void(int)> solve = [&] (int i) {
        if (i == n) {
            ans++;
            return;
        }

        for (auto j = 0; j < n; ++j) {
            // Check if j works
            if (col[j]) continue;
            if (diag1[i + j]) continue;
            if (diag2[n - 1 - i + j]) continue;
            if (board[i][j] == '*') continue;

            // Load j
            col[j] = true;
            diag1[i + j] = true;
            diag2[n - 1 - i + j] = true;

            solve(i + 1);

            // Unload j
            col[j] = false;
            diag1[i + j] = false;
            diag2[n - 1 - i + j] = false;
        }
    };

    solve(0);

    std::cout << ans << std::endl;

    return 0;
}
