#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int nK, nQ;
    cin >> nK >> nQ;

    vector<int> aK(nK), aQ(nQ);
    for (auto &x: aK) cin >> x;
    for (auto &x: aQ) cin >> x;

    int k = aK.front();

    sort(aK.begin(), aK.end());
    for (auto n: aQ) {
        cout << min(n, k - 1) << ' ';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
