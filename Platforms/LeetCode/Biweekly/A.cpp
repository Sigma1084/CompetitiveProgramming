#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<bool> colAv;
    vector<bool> diag1Av;  // [i + j]
    vector<bool> diag2Av;  // [n - 1 - i + j]
    vector<int> pos;
    vector<vector<string>> res;

    void appendToAnswer(const vector<int> &pos) {
        vector<string> ans = vector<string>(n, string(n, '.'));
        for (auto i = 0; i < n; ++i) {
            ans[i][pos[i]] = 'Q';
        }
        res.push_back(ans);
    }

    void solve() {
        if (pos.size() == std::size_t(n)) {
            appendToAnswer(pos);
            return;
        }

        int i = pos.size();
        pos.push_back(0);
        for (auto j = 0; j < n; ++j) {
            // Check if j works
            if (not colAv[j]) continue;
            if (not diag1Av[i + j]) continue;
            if (not diag2Av[n - 1 - i + j]) continue;

            // Load j
            pos.back() = j;
            colAv[j] = false;
            diag1Av[i + j] = false;
            diag2Av[n - 1 - i + j] = false;

            solve();

            // Unload j
            colAv[j] = true;
            diag1Av[i + j] = true;
            diag2Av[n - 1 - i + j] = true;
        }
        pos.pop_back();
    }

public:
    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        colAv.resize(n, true);
        diag1Av.resize(2*n - 1, true);
        diag2Av.resize(2*n - 1, true);
        solve();
        return res;
    }
};


int main() {
    Solution sol;
    int n;
    cin >> n;
    auto res = sol.solveNQueens(n);
    for (auto &ans : res) {
        for (auto &row : ans) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
