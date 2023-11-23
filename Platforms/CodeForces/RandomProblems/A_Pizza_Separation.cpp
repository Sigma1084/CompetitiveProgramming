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

    int s = 360;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = i; j < n; ++j) {
            // Take i to j
            cur += a[j];
            s = min(s, abs(360 - 2 * cur));
        }
    }

    cout << s << endl;

    return 0;
}
