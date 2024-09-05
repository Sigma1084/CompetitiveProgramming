#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    for (int i = 0; i < k; ++i) {
        cout << a[i] << ' ';
    }
    cout << x << ' ';
    for (int i = k; i < n; ++i) {
        cout << a[i] << ' ';
    }

    return 0;
}
