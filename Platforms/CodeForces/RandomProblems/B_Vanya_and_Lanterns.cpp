#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, l;
    std::cin >> n >> l;

    std::vector<int> a(n);
    for (auto &x: a) {
        std::cin >> x;
    }
    std::sort(a.begin(), a.end());

    int ans = std::max(a[0], l - a[n - 1]) * 2;
    for (int i = 1; i < n; ++i) {
        ans = std::max(ans, a[i] - a[i - 1]);
    }

    std::cout << ans / 2 << '.' << (ans & 1 ? 5 : 0);

    return 0;
}
