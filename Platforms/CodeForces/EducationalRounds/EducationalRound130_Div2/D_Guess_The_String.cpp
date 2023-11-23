#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 0-indexing
char ask1(int index) {
    cout << "? 1 " << index + 1 << endl;
    char c; cin >> c;
    return c;
}

// 0-indexing
int ask2(int l, int r) {
    cout << "? 2 " << l + 1 << ' ' << r + 1 << endl;
    int x; cin >> x;
    return x;
}

int main() {
    int n;
    cin >> n;

    string ans;
    vector<pair<int, char>> v;

    for (int i = 0, cur; i < n; ++i) {
        cur = ask2(0, i);
        if (cur != int(v.size())) {
            assert(cur == int(v.size()) + 1);
            v.emplace_back(i, ask1(i));
            ans += v.back().second;
            continue;
        }

        // Binary search
        int l = 1, r = int(v.size() - 1), m;
        while (l <= r) {
            m = (l + r) / 2;
            if (ask2(v[m].first, i) == cur - m) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        ans += v[r].second;
        v.erase(v.begin() + r);
        v.emplace_back(i, ans.back());
    }

    cout << "! " << ans << endl;

    return 0;
}
