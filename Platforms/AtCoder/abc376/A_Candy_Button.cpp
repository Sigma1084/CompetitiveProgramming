#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int ans = 0;
    for (int i = 0, j; i < n; i = j) {
        ans += 1;
        for (j = i; j < n and a[j] - a[i] < c; ++j);
    }

    cout << ans << '\n';

    return 0;
}
