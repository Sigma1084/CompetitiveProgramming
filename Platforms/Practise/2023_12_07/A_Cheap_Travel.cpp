#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if (a * m <= b) {
        cout << n * a;
        return 0;
    }

    int ans = b * (n / m);
    n %= m;
    ans += min(n * a, b);

    cout << ans;

    return 0;
}
