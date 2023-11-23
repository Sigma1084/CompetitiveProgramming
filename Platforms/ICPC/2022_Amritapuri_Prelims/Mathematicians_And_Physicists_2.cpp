#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, nQ;
    cin >> n >> nQ;

    array<vector<array<int, 2>>, 2> queries{};
    for (int i = 0; i < nQ; ++i) {
        int t, l, r;
        cin >> t >> l >> r;
        --t; --l; --r;
        queries[t].push_back({l, r});
    }

    vector<int> a(n);
    vector<int> b{a.begin(), a.end()};

    // Simplify the type 1 queries
    sort(queries[0].begin(), queries[0].end());
    for (int i = 0; i < n; ++i) {

    }


    return 0;
}
