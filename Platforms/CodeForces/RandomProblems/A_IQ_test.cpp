#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<vector<int>> b(2);

    for (int i = 0; i < n; ++i) {
        b[a[i] % 2].push_back(i + 1);
    }

    if (b[0].size() == 1) {
        cout << b[0][0];
    } else {
        cout << b[1][0];
    }

    return 0;
}
