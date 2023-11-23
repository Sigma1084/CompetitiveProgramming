#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 3>> a(2 * n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a[2*i] = {l, 0, i};
        a[2*i + 1] = {r, 1, i};
    }
    sort(a.begin(), a.end());

    vector<int> ans(n);
    queue<int> rooms;
    int numRooms = 0;

    for (auto [_, dx, idx]: a) {
        if (dx == 1) {
            rooms.push(ans[idx]);
        } else if (rooms.empty()) {
            ans[idx] = ++numRooms;
        } else {
            ans[idx] = rooms.front();
            rooms.pop();
        }
    }

    cout << numRooms << '\n';
    for (int x: ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
