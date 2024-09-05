#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> a(n + m);
    for (auto &[x, _]: a) {
        cin >> x;
    }
    for (int i = 0; i < n; ++i) {
        a[i][1] = 0;
    }
    for (int i = n; i < n + m; ++i) {
        a[i][1] = 1;
    }
    sort(a.begin(), a.end());

    for (int i = 1; i < n + m; ++i) {
        if (a[i][1] == 0 and a[i-1][1] == 0) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
    return 0;
}
