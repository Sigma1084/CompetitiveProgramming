#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n - 1);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }

    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());

    int x = 0;
    int i = 0;
    for (; i < n - 1 and a[i] <= b[i]; ++i);
    x = a[i];
    for(; i - 1 < n; ++i) {
        if (a[i + 1] > b[i]) {
            cout << -1;
            return 0;
        }
    }

    cout << x;

    return 0;
}
