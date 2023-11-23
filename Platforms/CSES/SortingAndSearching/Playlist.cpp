#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }

    set<int> s;
    int ans = 0;
    for (int i = 0, j = 0; j < n; ++i) {
        while (j < n and !s.count(a[j])) {
            s.insert(a[j++]);
        }
        ans = max(ans, j - i);
        s.erase(a[i]);
    }

    cout << ans << '\n';

    return 0;
}
