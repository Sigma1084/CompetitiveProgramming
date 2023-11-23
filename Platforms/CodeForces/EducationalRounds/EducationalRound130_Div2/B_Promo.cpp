#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, nQ;
    cin >> n >> nQ;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end(), greater<>());

    vector<ll> p(n + 1);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i];
    }

    for (int x, y; nQ--; ) {
        cin >> x >> y;
        cout << p[x] - p[x - y] << '\n';
    }

    return 0;
}
