#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, cl, ce, v;
    cin >> n >> m >> cl >> ce >> v;

    vector<int> l(cl);
    for (auto &x : l) {
        cin >> x;
    }

    vector<int> e(ce);
    for (auto &x : e) {
        cin >> x;
    }

    int nQ;
    cin >> nQ;

    while (nQ--) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }

        if (y1 == y2) {
            cout << abs(x2 - x1) << "\n";
            continue;
        }

        // x1 < x2 ensured
        // Always take the one after x1 if possible

        int ans = INT_MAX;

        // Right stairs to x1
        int i = upper_bound(l.begin(), l.end(), x1) - l.begin() - 1;
        if (i >= 0) {
            ans = min(ans, abs(x1 - l[i]) + abs(x2 - l[i]) + 
                abs(y2 - y1));
        }

        // Left stairs to x1
        if (i + 1 < cl) {
            ans = min(ans, abs(x1 - l[i+1]) + abs(x2 - l[i+1]) + 
                abs(y2 - y1));
        }

        i = upper_bound(e.begin(), e.end(), x1) - e.begin() - 1;
        if (i >= 0) {
            ans = min(ans, abs(x1 - e[i]) + abs(x2 - e[i]) 
                + (abs(y2 - y1) + v - 1) / v);
        }

        if (i + 1 < ce) {
            ans = min(ans, abs(x1 - e[i+1]) + abs(x2 - e[i+1]) 
                + (abs(y2 - y1) + v - 1) / v);
        }

        cout << ans << "\n";
    }

    return 0;
}
