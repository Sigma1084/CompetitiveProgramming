#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, nQ;
    cin >> n >> nQ;

    int ans = 0, l = 0, r = 1;
    while (nQ--) {
        char c;
        int p;
        cin >> c >> p;
        --p;

        int &x = (c == 'L') ? l : r;
        const int y = l + r - x;

        if (x > p) {
            if (x > y and y > p) {
                ans += n - (x - p);
            } else {
                ans += x - p;
            }
        } else {
            if (p > y and y > x) {
                ans += n - (p - x);
            } else {
                ans += p - x;
            }
        }

        x = p;
    }

    cout << ans << endl;

    return 0;
}
