#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> cur;
vector<vector<int>> cuts;

void recurse(int k) {
    if (k == 0) {
        cuts.push_back(cur);
        return;
    }
    int start = cur.empty() ? 1 : cur.back();
    for (int i = start; i <= k; ++i) {
        cur.push_back(i);
        recurse(k - i);
        cur.pop_back();
    }
}

map<int, pair<int, vector<int>>> dp;

constexpr int N = 3'188'646;
void preCompute() {
    recurse(41);
    for (const auto &cut: cuts) {
        int prod = accumulate(cut.begin(), cut.end(), 1, multiplies<int>());
        if (dp.count(prod) == size_t(0) or size_t(dp[prod].first) > cut.size()) {
            dp[prod] = {cut.size(), cut};
        }
    }
}

void solve() {
    int n; cin >> n;

    if (dp.find(n) == dp.end()) {
        cout << -1;
    } else {
        auto [k, cut] = dp[n];
        cout << k << ' ';
        for (int i = 0; i < k; ++i) {
            cout << cut[i] << ' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string file_name = "sum_41_chapter_1";

    freopen((file_name + "_input.txt").c_str(), "r", stdin);
    freopen((file_name + "_output.txt").c_str(), "w", stdout);

    int t = 1;
    cin >> t;

    preCompute();

    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }

    return 0;
}

