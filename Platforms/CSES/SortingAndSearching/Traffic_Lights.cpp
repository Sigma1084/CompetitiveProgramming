#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int r, n;
    cin >> r >> n;

    set<int> s = {0, r};  // light positions
    multiset<int, greater<>> ms = {r};  // light distances
    for (int i = 0, x; i < n; ++i) {
        cin >> x;

        // Calculate the closest lights.
        auto it = s.lower_bound(x);
        int r = *it;
        int l = *prev(it);

        // Update the light distances.
        ms.erase(ms.find(r - l));
        ms.insert(x - l);
        ms.insert(r - x);

        // Insert the new light.
        s.insert(x);

        // Print the maximum light distance.
        cout << *ms.begin() << ' ';
    }

    return 0;
}
