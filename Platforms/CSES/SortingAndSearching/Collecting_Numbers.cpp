#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> pos(n);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        pos[x - 1] = i;
    }

    int ans = 1;
    for (int i = 0; i + 1 < n; ++i) {
        ans += pos[i] > pos[i + 1];
    }

    cout << ans << '\n';

    return 0;
}
