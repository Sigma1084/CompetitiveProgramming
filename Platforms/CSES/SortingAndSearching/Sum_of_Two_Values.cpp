#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, sum;
    std::cin >> n >> sum;

    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][0];
        a[i][1] = i + 1;
    }
    std::sort(a.begin(), a.end());

    for (int i = 0, j = n - 1; i < j; ) {
        if (a[i][0] + a[j][0] == sum) {
            std::cout << a[i][1] << ' ' << a[j][1] << '\n';
            return 0;
        } else if (a[i][0] + a[j][0] < sum) {
            i++;
        } else {
            j--;
        }
    }
    std::cout << "IMPOSSIBLE\n";

    return 0;
}
