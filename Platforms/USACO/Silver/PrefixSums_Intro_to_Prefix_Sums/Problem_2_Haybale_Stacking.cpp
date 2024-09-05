#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        a[l]++;
        a[r + 1]--;
    }

    for (int i = 1; i <= n; ++i) {
        a[i] += a[i - 1];
    }
    assert(a[n] == 0);

    sort(a.begin(), a.end() - 1);
    cout << a[n / 2] << '\n';

    return 0;
}
