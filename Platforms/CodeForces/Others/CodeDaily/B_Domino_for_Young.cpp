#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll b = 0, w = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        b += x / 2;
        w += x / 2;
        if (x % 2 == 1) {
            if (i % 2 == 0) {
                ++b;
            } else {
                ++w;
            }
        }
    }

    cout << min(b, w) << '\n';

    return 0;
}
